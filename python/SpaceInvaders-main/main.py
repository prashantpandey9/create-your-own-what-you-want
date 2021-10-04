import pygame
import random
import math
from pygame import mixer

# initialization
pygame.init()
screen = pygame.display.set_mode((800, 600))  # height , width of display screen

# Background
background = pygame.image.load('background.png')

# Background sound
mixer.music.load('background.wav')
mixer.music.play(-1)

# Title
pygame.display.set_caption("Space Invaders")
icon = pygame.image.load("project (1).png")
pygame.display.set_icon(icon)

# player
playerImg = pygame.image.load('001-spaceship.png')
playerX = 370
playerY = 480

playerX_chg = 0

# Enemy
enemyX = []
enemyY = []
enemyImg = []
enemyX_chg = []
enemyY_chg = []
number_of_enemies = 5
for i in range(number_of_enemies):
    enemyImg.append(pygame.image.load('ufo.png'))
    enemyX.append(random.randint(0, 736))
    enemyY.append(random.randint(50, 150))
    enemyX_chg.append(2)
    enemyY_chg.append(20)

# bullet

bulletImg = pygame.image.load('bullet.png')
bulletX = 0
bulletY = 480
bulletX_change = 0
bulletY_change = 10
bullet_state = "ready"

# Score
score_value = 0
font = pygame.font.Font('freesansbold.ttf', 32)

textX = 10
textY = 10

over_font = pygame.font.Font('freesansbold.ttf', 100)


def game_over_text():
    over_text = font.render('GAME OVER :' + str(score_value), True, (255, 255, 255))
    screen.blit(over_text, (200, 250))


def show_score(x, y):
    score = font.render("Score :" + str(score_value), True, (0, 255, 0))
    screen.blit(score, (textX, textY))


def player(x, y):
    screen.blit(playerImg, (x, y))


def enemy(x, y, i):
    screen.blit(enemyImg[i], (x, y))


def fire_bullet(x, y):
    global bullet_state
    bullet_state = "fire"
    screen.blit(bulletImg, (x + 16, y + 10))


def isCollision(enemyX, enemyY, bulletX, bulletY):
    distance = math.sqrt(math.pow(enemyX - bulletX, 2) + math.pow(enemyY - bulletY, 2))
    if distance < 27:
        return True
    else:
        return False


# Gameloop    First Window

running = True
while running:
    screen.fill((255, 255, 255))  # rgb value
    screen.blit(background, (0, 0))  # background image

    for event in pygame.event.get():  # all events any key pressed is event
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                playerX_chg = -3
            if event.key == pygame.K_RIGHT:
                playerX_chg = +3
            if event.key == pygame.K_SPACE:
                if bullet_state == 'ready':
                    bullet_sound = mixer.Sound('laser.wav')
                    bullet_sound.play()
                    bulletX = playerX
                fire_bullet(bulletX, bulletY)
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                playerX_chg = 0
            if event.key == pygame.K_RIGHT:
                playerX_chg = 0

    playerX += playerX_chg
    if playerX <= 0:
        playerX = 0
    elif playerX >= 736:
        playerX = 736

        # Enemy Movement
    for i in range(number_of_enemies):

        # GameOver
        if enemyY[i] > 440:
            for j in range(number_of_enemies):
                enemyY[j] = 1000
            game_over_text()
            bullet_state="ready"
            break

        enemyX[i] += enemyX_chg[i]
        if enemyX[i] <= 0:
            enemyX_chg[i] = 2
            enemyY[i] += enemyY_chg[i]
        elif enemyX[i] >= 736:
            enemyX_chg[i] = -2
            enemyY[i] += enemyY_chg[i]

        # Collision
        collision = isCollision(enemyX[i], enemyY[i], bulletX, bulletY)
        if collision:
            explosion_sound = mixer.Sound('explosion.wav')
            explosion_sound.play()
            bulletY = 480
            bullet_state = "ready"
            score_value += 1
            enemyX[i] = random.randint(0, 735)
            enemyY[i] = random.randint(50, 150)

        enemy(enemyX[i], enemyY[i], i)

    # Bullet Movement
    if bulletY <= 0:
        bulletY = 480
        bullet_state = "ready"

    if bullet_state == 'fire':
        fire_bullet(bulletX, bulletY)
        bulletY -= bulletY_change

    player(playerX, playerY)
    show_score(textX, textY)
    pygame.display.update()
