"""https://www.pygame.org/docs/ref/event.html"""
import pygame
import time
import random

pygame.init()

white = (255,255,255)
black = (0,0,0)
red   = (255, 0, 0)
green= (0, 155, 0)

display_width  = 800
display_height = 600

gameDisplay = pygame.display.set_mode((display_width,display_height))
pygame.display.set_caption('Slither')

img = pygame.image.load('head.png')

font = pygame.font.SysFont(None, 25)

def text_object(text, color):
    textSurface = font.render(text, True, color)
    return textSurface, textSurface.get_rect()

def message_to_screen(msg, color):
    textSurface, textRect = text_object(msg, color)
    textRect.center = (display_width / 2), (display_height / 2)
    gameDisplay.blit(textSurface, textRect)

def snake(block_size, snakeList):
    gameDisplay.blit(img, (snakeList[-1][0], snakeList[-1][1]))
    for XnY in snakeList[:-1]:
        pygame.draw.rect(gameDisplay, green, [XnY[0], XnY[1], block_size, block_size])

def gameLoop():
    lead_x = display_width/2
    lead_y = display_height/2
    lead_x_change = 0
    lead_y_change = 0

    block_size = 20
    FPS = 15

    clock = pygame.time.Clock()
        
    gameOver = False
    gameExit = False

    snakeList = []
    snakeLength = 1

    randAppleX = round(random.randrange(0, display_width-block_size)/10.0)*10.0
    randAppleY = round(random.randrange(0, display_height-block_size)/10.0)*10.0
    
    while not gameExit:

        while gameOver == True:
            gameDisplay.fill(white)
            message_to_screen("Game over, press C to play again or Q to quit", red)
            pygame.display.update()

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
                    lead_x_change = -block_size
                    lead_y_change = 0
                elif event.key == pygame.K_RIGHT:
                    lead_x_change = block_size
                    lead_y_change = 0
                elif event.key == pygame.K_UP:
                    lead_y_change = -block_size
                    lead_x_change = 0
                elif event.key == pygame.K_DOWN:
                    lead_y_change = block_size
                    lead_x_change = 0

        if lead_x >= display_width or lead_x <= 0 or lead_y >= display_height or lead_y <= 0:
            gameOver = True
        
        lead_x += lead_x_change
        lead_y += lead_y_change           
        gameDisplay.fill(white)

        appleThickness = 30
        pygame.draw.rect(gameDisplay, red, [randAppleX, randAppleY, appleThickness, appleThickness])

        snakeHead = []

        snakeHead.append(lead_x)
        snakeHead.append(lead_y)
        snakeList.append(snakeHead)

        if len(snakeList) > snakeLength:
            del snakeList[0]

        for eachSegment in snakeList[:-1]:
            if eachSegment == snakeHead:
                gameOver = True

        snake(block_size, snakeList)
        pygame.display.update()

##        if lead_x >= randAppleX and lead_x <= randAppleX + appleThickness:
##            if lead_y >= randAppleY and lead_y <= randAppleY + appleThickness:
##                print("om nom nom")
##                randAppleX = round(random.randrange(0, display_width-block_size)/10.0)*10.0
##                randAppleY = round(random.randrange(0, display_height-block_size)/10.0)*10.0
##                snakeLength += 1        q
        if lead_x >= randAppleX and lead_x <= randAppleX + appleThickness or lead_x + block_size >= randAppleX and lead_x + block_size <= randAppleX + appleThickness:
            if lead_y >= randAppleY and lead_y <= randAppleY + appleThickness: 
                print("om nom nom")
                randAppleX = round(random.randrange(0, display_width-block_size)/10.0)*10.0
                randAppleY = round(random.randrange(0, display_height-block_size)/10.0)*10.0
                snakeLength += 1
            elif lead_y + block_size >= randAppleY and lead_y + block_size <= randAppleY + appleThickness:
                print("om nom nom")
                randAppleX = round(random.randrange(0, display_width-block_size)/10.0)*10.0
                randAppleY = round(random.randrange(0, display_height-block_size)/10.0)*10.0
                snakeLength += 1
        clock.tick(FPS)

    pygame.quit()
    quit() 

gameLoop()
