from django.shortcuts import render
import random

# Constants for the game
CARD_RANKS = ['3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A', '2', 'Joker']
CARD_SUITS = ['Hearts', 'Diamonds', 'Clubs', 'Spades']
TOTAL_CARDS = 52

def generate_deck():
    """Generates a standard deck of cards."""
    deck = [rank + ' of ' + suit for rank in CARD_RANKS[:-1] for suit in CARD_SUITS]
    deck.append('Joker')  # Adding one Joker card for simplicity
    random.shuffle(deck)
    return deck

def deal_cards(deck, num_players):
    """Distributes cards equally among players."""
    return [deck[i::num_players] for i in range(num_players)]

def simulate_bot_move(bot_hand, top_cards, difficulty):
    """Simulates the move of a bot based on the difficulty."""
    if difficulty == 'easy':
        # 50% chance to play a random card
        if random.random() < 0.5 and bot_hand:
            return bot_hand.pop(random.randint(0, len(bot_hand) - 1))
    elif difficulty == 'medium':
        # 20% chance to play a random card
        if random.random() < 0.2 and bot_hand:
            return bot_hand.pop(random.randint(0, len(bot_hand) - 1))
    # Play the smallest valid card if possible
    valid_cards = [card for card in bot_hand if is_valid_move(card, top_cards)]
    if valid_cards:
        chosen_card = min(valid_cards, key=lambda c: CARD_RANKS.index(c.split(' ')[0]))
        bot_hand.remove(chosen_card)
        return chosen_card
    return None

def is_valid_move(card, top_cards):
    """Determines if the card can beat the top cards."""
    if not top_cards:
        return True
    top_rank = top_cards[0].split(' ')[0]
    card_rank = card.split(' ')[0]
    return CARD_RANKS.index(card_rank) > CARD_RANKS.index(top_rank)

def main_menu(request):
    return render(request, 'main_menu.html')

def game_view(request, difficulty):
    num_opponents = int(request.GET.get('opponents', 1))
    num_players = num_opponents + 1

    if num_players < 2 or num_players > 15:
        return render(request, 'error.html', {'message': 'Invalid number of players. Must be between 2 and 15.'})

    deck = generate_deck()
    hands = deal_cards(deck, num_players)
    player_hand = hands[0]
    bot_hands = hands[1:]

    context = {
        'difficulty': difficulty,
        'player_hand': player_hand,
        'bot_hands': bot_hands,
        'top_cards': []
    }
    return render(request, 'game.html', context)

def easy_mode(request):
    return game_view(request, 'easy')

def medium_mode(request):
    return game_view(request, 'medium')

def hard_mode(request):
    return game_view(request, 'hard')
