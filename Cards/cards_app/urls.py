from django.urls import path
from . import views

urlpatterns = [
    path('', views.main_menu, name='main_menu'),
    path('easy/', views.easy_mode, name='easy_mode'),
    path('medium/', views.medium_mode, name='medium_mode'),
    path('hard/', views.hard_mode, name='hard_mode'),
]
