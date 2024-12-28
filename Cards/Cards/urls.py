from django.contrib import admin
from django.urls import path
from . import views

urlpatterns = [
    path("admin/", admin.site.urls),
    path('', views.main_menu, name='main_menu'),
    path('easy/', views.easy_mode, name='easy_mode'),
    path('medium/', views.medium_mode, name='medium_mode'),
    path('hard/', views.hard_mode, name='hard_mode'),
    path('game/<str:difficulty>/', views.game_view, name='game'),
    path('play_card/', views.play_card, name='play_card'),
]
