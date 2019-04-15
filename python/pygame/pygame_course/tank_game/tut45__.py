"""https://www.pygame.org/docs/ref/event.html"""
import pygame
import time
import random

pygame.init()
clock = pygame.time.Clock()

white = (255,255,255)
black = (0,0,0)
red   = (255, 0, 0)
green= (0, 155, 0)

display_width  = 800
display_height = 600

gameDisplay = pygame.display.set_mode((display_width,display_height))
pygame.display.set_caption('Tank')

smallfont = pygame.font.SysFont("comicsansms", 25)
medfont = pygame.font.SysFont("comicsansms", 50)
lagfont = pygame.font.SysFont("comicsansms", 80)

def text_object(text, color, size):
    if size == "small":
        textSurface = smallfont.render(text, True, color)
    if size == "medium":
        textSurface = medfont.render(text, True, color)
    if size == "large":
        textSurface = lagfont.render(text, True, color)

    return textSurface, textSurface.get_rect()

def message_to_screen(msg, color, y_display=0, size="small"):
    textSurface, textRect = text_object(msg, color, size)
    textRect.center = (display_width / 2), (display_height / 2) + y_display
    gameDisplay.blit(textSurface, textRect)

def score(score):
    text = smallfont.render("Score: " + str(score), True, black)
    gameDisplay.blit(text, [0,0])

def pause():
    # gameDisplay.fill(white)
    message_to_screen("PAUSED",
                        red,
                        size = "large")

    message_to_screen("Press C to continue, Q to quit",
                        black, 
                        100)

    pygame.display.update()

    paused = True
    while paused:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_c:
                    paused = False
                if event.key == pygame.K_q:
                    pygame.quit()
                    quit()
        clock.tick(5)

def game_intro():
    intro = True

    while intro:
        gameDisplay.fill(white)
        message_to_screen("Welcome to Tanks", 
                            green, 
                            -100, 
                            "large")
        message_to_screen("The objective of the game is to destroy enemy tanks", 
                            black, 
                            -30)
        message_to_screen("The more tanks you destroy, the harder it gets", 
                            black, 
                            10)
        message_to_screen("If you run out of energy, you die!", 
                            black, 
                            50) 
        message_to_screen("Press C to play or Q to quit", 
                            black, 
                            180)
        pygame.display.update()
        clock.tick(15)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_c:
                    intro = False
                if event.key == pygame.K_q:
                    pygame.quit()
                    quit()

def gameLoop():

    block_size = 20
    FPS = 15
        
    gameOver = False
    gameExit = False
    
    while not gameExit:
        if gameOver == True:
            message_to_screen("Game over",
                  red,
                  y_display = -50,
                  size = "large")
            
            message_to_screen("Press C to play again or Q to quit", black,
                              50,
                              "small")
            pygame.display.update()

        while gameOver == True:
            # gameDisplay.fill(white)

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    gameExit = True
                    gameOver = False        
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        gameOver = False
                        gameExit = True
                    if event.key == pygame.K_c:
                        gameLoop()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                gameExit = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    pass
                elif event.key == pygame.K_RIGHT:
                    pass
                elif event.key == pygame.K_UP:
                    pass
                elif event.key == pygame.K_DOWN:
                    pass
                elif event.key == pygame.K_p:
                    pause()
          
        gameDisplay.fill(white)
        pygame.display.update()
        clock.tick(FPS)

    pygame.quit()
    quit() 

game_intro()
gameLoop()
