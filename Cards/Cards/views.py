from django.shortcuts import render, redirect
import random

CARD_RANKS = ['3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A', '2', 'Joker']
CARD_SUITS = ['Hearts', 'Diamonds', 'Clubs', 'Spades']
TOTAL_CARDS = 52

def generate_deck():
    deck = [rank + ' of ' + suit for rank in CARD_RANKS[:-1] for suit in CARD_SUITS]
    deck.append('Joker')
    random.shuffle(deck)
    return deck

def deal_cards(deck, num_players):
    return [deck[i::num_players] for i in range(num_players)]

def simulate_bot_move(bot_hand, top_cards, difficulty):
    if difficulty == 'easy':
        if random.random() < 0.5 and bot_hand:
            return bot_hand.pop(random.randint(0, len(bot_hand) - 1))
    elif difficulty == 'medium':
        if random.random() < 0.2 and bot_hand:
            return bot_hand.pop(random.randint(0, len(bot_hand) - 1))
    valid_cards = [card for card in bot_hand if is_valid_move(card, top_cards)]
    if valid_cards:
        chosen_card = min(valid_cards, key=lambda c: CARD_RANKS.index(c.split(' ')[0]))
        bot_hand.remove(chosen_card)
        return chosen_card
    return None

def is_valid_move(card, top_cards):
    if not top_cards:
        return True
    top_rank = top_cards[0].split(' ')[0]
    card_rank = card.split(' ')[0]
    return CARD_RANKS.index(card_rank) > CARD_RANKS.index(top_rank)

def main_menu(request):
    return render(request, 'main_menu.html')

def game_view(request, difficulty):
    if 'reset' in request.GET or 'game_state' not in request.session:
        num_opponents = int(request.GET.get('opponents', 1))
        num_players = num_opponents + 1

        if num_players < 2 or num_players > 15:
            return render(request, 'error.html', {'message': 'Invalid number of players. Must be between 2 and 15.'})

        deck = generate_deck()
        hands = deal_cards(deck, num_players)
        player_hand = hands[0]
        bot_hands = hands[1:]

        bot_difficulties = [difficulty] * num_opponents

        turn = request.session.get('last_winner', 0)

        game_state = {
            'difficulty': difficulty,
            'player_hand': player_hand,
            'bot_hands': bot_hands,
            'bot_difficulties': bot_difficulties,
            'top_cards': [],
            'turn': turn,
        }
        request.session['game_state'] = game_state
        request.session.modified = True
    else:
        game_state = request.session['game_state']

    return render(request, 'game.html', game_state)

def is_valid_move(card, top_cards):
    if not top_cards:
        return True
    top_rank = top_cards[0].split(' ')[0]
    card_rank = card.split(' ')[0]
    return CARD_RANKS.index(card_rank) > CARD_RANKS.index(top_rank)

from django.contrib import messages

def play_card(request):
    game_state = request.session.get('game_state')
    if not game_state:
        messages.error(request, "Game state not found.")
        return redirect('game', difficulty=game_state.get('difficulty', 'easy'))

    player_hand = game_state['player_hand']
    bot_hands = game_state['bot_hands']
    top_cards = game_state['top_cards']
    difficulty = game_state['difficulty']
    turn = game_state['turn']
    num_players = 1 + len(bot_hands)

    if turn == 0:
        if 'take' in request.POST:
            player_hand.extend(top_cards)
            game_state['top_cards'] = []
            messages.info(request, "You picked up the pile.")
        else:
            card_index = request.POST.get('card_index')

            if card_index is None or card_index == '':
                messages.error(request, "Invalid card index.")
                return redirect('game', difficulty=difficulty)

            try:
                card_index = int(card_index)
            except ValueError:
                messages.error(request, "Invalid card index.")
                return redirect('game', difficulty=difficulty)

            if card_index < 0 or card_index >= len(player_hand):
                messages.error(request, "Card index out of range.")
                return redirect('game', difficulty=difficulty)

            chosen_card = player_hand[card_index]
            if not is_valid_move(chosen_card, top_cards):
                messages.error(request, "You cannot play a card with a lower or equal value.")
                return redirect('game', difficulty=difficulty)

            player_hand.pop(card_index)
            game_state['top_cards'] = [chosen_card]

    else:
        bot_hand = bot_hands[turn - 1]
        valid_cards = [card for card in bot_hand if is_valid_move(card, top_cards)]
        if valid_cards:
            chosen_card = min(valid_cards, key=lambda c: CARD_RANKS.index(c.split(' ')[0]))
            bot_hand.remove(chosen_card)
            game_state['top_cards'] = [chosen_card]
        else:
            bot_hand.extend(top_cards)
            game_state['top_cards'] = []

    if not player_hand:
        del request.session['game_state']
        return render(request, 'win.html')
    elif all(not hand for hand in bot_hands):
        del request.session['game_state']
        return render(request, 'lose.html')

    game_state['turn'] = (turn + 1) % num_players
    request.session['game_state'] = game_state
    request.session.modified = True

    if game_state['turn'] != 0:
        return play_card(request)

    return redirect('game', difficulty=difficulty)

def easy_mode(request):
    return game_view(request, 'easy')

def medium_mode(request):
    return game_view(request, 'medium')

def hard_mode(request):
    return game_view(request, 'hard')
