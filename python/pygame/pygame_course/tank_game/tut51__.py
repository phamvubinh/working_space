"""https://www.pygame.org/docs/ref/event.html"""
import pygame
import time
import random

pygame.init()
clock = pygame.time.Clock()

white = (255,255,255)
black = (0,0,0)

red = (200,0,0)
light_red = (255,0,0)

yellow = (200,200,0)
light_yellow = (255,255,0)

green = (34,177,76)
light_green = (0,255,0)

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

def text_to_button(msg, color, buttonx, buttony, buttonwidth, buttonheight, size="small"):
    textSurf, textRect = text_object(msg, color, size)
    textRect.center = ((buttonx + buttonwidth/2), (buttony + buttonheight/2))
    gameDisplay.blit(textSurf, textRect)

def message_to_screen(msg, color, y_display=0, size="small"):
    textSurface, textRect = text_object(msg, color, size)
    textRect.center = (display_width / 2), (display_height / 2) + y_display
    gameDisplay.blit(textSurface, textRect)

def button(text, posX, posY, width, height, inactive_color, active_color, action = None):
    cur = pygame.mouse.get_pos()

    click = pygame.mouse.get_pressed()
    # print(click)

    if posX + width > cur[0] > posX and posY + height > cur[1] > posY:
        pygame.draw.rect(gameDisplay, active_color, (posX, posY, width, height))
        if click[0] == 1 and action != None:
            if action == "play":
                gameLoop()
            if action == "controls":
                pass
            if action == "quit":
                pygame.quit()
                quit()

    else:
        pygame.draw.rect(gameDisplay, inactive_color, (posX, posY, width, height))

    # pygame.draw.rect(gameDisplay, yellow, (350, 500, 100, 50))
    # pygame.draw.rect(gameDisplay, red, (550, 500, 100, 50))

    text_to_button(text, black, posX, posY, width, height)

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
                            100)

        
        button("play", 150, 500, 100, 50, green, light_green, action = "play")
        button("controls", 350, 500, 100, 50, yellow, light_yellow, action = "controls")
        button("quit", 550, 500, 100, 50, red, light_red, action = "quit")

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
