"""https://www.pygame.org/docs/ref/event.html"""
import pygame

pygame.init()

white = (255,255,255)
black = (0,0,0)

head  = [400, 300, 20, 20]
tail  = [200, 200, 20,  100]

gameDisplay = pygame.display.set_mode((800,600)) #surface

pygame.display.set_caption('Slither')


#pygame.display.flip()

pygame.display.update()

gameExit = False

lead_x = 300
lead_y = 300

while not gameExit:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            gameExit = True

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                lead_x -= 10
            if event.key == pygame.K_RIGHT:
                lead_x += 10
    gameDisplay.fill(white)

    pygame.draw.rect(gameDisplay, black, [lead_x, lead_y, 10, 10])

    pygame.display.update()

pygame.quit()

quit() 

