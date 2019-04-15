"""https://www.pygame.org/docs/ref/event.html"""
import pygame

pygame.init()


gameDisplay = pygame.display.set_mode((800,600)) #surface

pygame.display.set_caption('Slither')


#pygame.display.flip()

pygame.display.update()

gameExit = False

while not gameExit:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            gameExit = True
        #print(event)
            

    

pygame.quit()

quit() 
