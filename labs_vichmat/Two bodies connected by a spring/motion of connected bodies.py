import pygame
import sys

# INITIAL SETTINGS
gravity = 5
mass = 30
# data = [209, 53, 238, 89, 106, 85, 0, 0, 0, 0]
# anchorX  Mass 1 Mass 2 V1 V2
# Mass 1
mass1PositionY = 238
mass1PositionX = 89
mass1VelocityY = 0

mass1VelocityX = 0

# Mass 2
mass2PositionY = 106
mass2PositionX = 85
mass2VelocityY = 0
mass2VelocityX = 0
anchorX = 209
anchorY = 53
data = [anchorX, anchorY, mass1PositionX, mass1PositionY, mass2PositionX, mass2PositionY, mass1VelocityX, mass1VelocityY, mass2VelocityX, mass2VelocityY]

timeStep = 0.28  # наша дельта Т

k = 2
damping = 2

FPS = 60
WIN_WIDTH = 800
WIN_HEIGHT = 600
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GRAY = (125, 125, 125)
LIGHT_BLUE = (64, 128, 255)
GREEN = (0, 200, 64)
YELLOW = (225, 225, 0)
PINK = (230, 50, 230)

clock = pygame.time.Clock()
sc = pygame.display.set_mode(
    (WIN_WIDTH, WIN_HEIGHT))

def Euler(data, n = 10, h = 0.01):
    sc.fill(WHITE)
    while True:
        for i in pygame.event.get():
            if i.type == pygame.QUIT:
                sys.exit()
        #sc.fill(WHITE)
        data_normal = data
        result_normal = spring(data_normal)
        for i in range(2, 10):
            data_normal[i] = result_normal[i - 2]

        for i in range(n):
            result = spring(data)
            for i in range(2, 10):
                data[i] = result[i - 2]
            data[3] += h * result[3]  # y1
            data[2] += h  # x1
            data[5] += h * result[5]  # y2
            data[4] += h  # x2
            # data[1] += h * result[3]  # y1
            # data[0] += h  # x1
            # data[3] += h * result[5]  # y2
            # data[2] += h  # x2

            # pygame.draw.rect(sc, BLACK, (data[0], data[1], 3, 3))
            # pygame.draw.rect(sc, BLACK, (data[2], data[3], 3, 3))

            pygame.draw.rect(sc, BLACK, (data_normal[0]-5, data_normal[1]-5, 10, 10))
            #pygame.draw.aaline(sc, PINK, [result_normal[0], result_normal[1]], [data_normal[0], data_normal[1]])
            #pygame.draw.aaline(sc, PINK, [result_normal[2], result_normal[3]], [result[0], result[1]])
            #pygame.draw.circle(sc, YELLOW, (result_normal[0], result_normal[1]), 20)
            #pygame.draw.circle(sc, YELLOW, (result_normal[2], result_normal[3]), 20)
            pygame.draw.rect(sc, BLACK, (data[2], data[3], 3, 3))
            pygame.draw.rect(sc, BLACK, (data[4], data[5], 3, 3))
            pygame.display.update()
        clock.tick(FPS)

    # return [data[2], data[3], data[4], data[5]]

def spring(data):
    anchorX = data[0]
    anchorY = data[1]
    mass1PositionX = data[2]
    mass1PositionY = data[3]
    mass2PositionX = data[4]
    mass2PositionY = data[5]
    mass1VelocityX = data[6]
    mass1VelocityY = data[7]
    mass2VelocityX = data[8]
    mass2VelocityY = data[9]

    # Mass1SpringForce
    mass1SpringForceY = -k * (mass1PositionY - anchorY)  # методы вычмата но под вопрососм

    mass1SpringForceX = -k * (mass1PositionX - anchorX)

    # Mass2SpringForce

    mass2SpringForceY = -k * (mass2PositionY - mass1PositionY)

    mass2SpringForceX = -k * (mass2PositionX - mass1PositionX)

    # Mass1daming

    mass1DampingForceY = damping * mass1VelocityY

    mass1DampingForceX = damping * mass1VelocityX

    # Mass2daming

    mass2DampingForceY = damping * mass2VelocityY

    mass2DampingForceX = damping * mass2VelocityX

    # Mass1netforce

    mass1ForceY = mass1SpringForceY + mass * gravity - mass1DampingForceY - mass2SpringForceY + mass2DampingForceY  # или здесь методы вычмата

    mass1ForceX = mass1SpringForceX - mass1DampingForceX - mass2SpringForceX + mass2DampingForceX

    # Mass2netforce

    mass2ForceY = mass2SpringForceY + mass * gravity - mass2DampingForceY

    mass2ForceX = mass2SpringForceX - mass2DampingForceX

    # Mass1acceleration

    mass1AccelerationY = mass1ForceY / mass

    mass1AccelerationX = mass1ForceX / mass

    # Mass2acceleration

    mass2AccelerationY = mass2ForceY / mass

    mass2AccelerationX = mass2ForceX / mass

    # Mass1velocity
    mass1VelocityY = mass1VelocityY + mass1AccelerationY * timeStep
    mass1VelocityX = mass1VelocityX + mass1AccelerationX * timeStep

    # Mass2velocity
    mass2VelocityY = mass2VelocityY + mass2AccelerationY * timeStep
    mass2VelocityX = mass2VelocityX + mass2AccelerationX * timeStep

    # Mass1position
    mass1PositionY = mass1PositionY + mass1VelocityY * timeStep
    mass1PositionX = mass1PositionX + mass1VelocityX * timeStep

    # Mass2position
    mass2PositionY = mass2PositionY + mass2VelocityY * timeStep
    mass2PositionX = mass2PositionX + mass2VelocityX * timeStep

    return [mass1PositionX, mass1PositionY, mass2PositionX, mass2PositionY, mass1VelocityX, mass1VelocityY, mass2VelocityX, mass2VelocityY]

def middle_point(data, n = 10, h = 0.01):
    while True:
        for i in pygame.event.get():
            if i.type == pygame.QUIT:
                sys.exit()
        sc.fill(WHITE)
        data_normal = data
        result_normal = spring(data_normal)
        for i in range(2, 10):
            data_normal[i] = result_normal[i - 2]

        for i in range(n):
            result = spring(data)
            for i in range(2, 10):
                data[i] = result[i - 2]

            k1_x = data[2]
            k1_y = data[3]
            k2_x = data[2] + h*k1_x/2
            k2_y = data[3] + h*k1_y/2
            data[2] = data[2] + h*k2_x
            data[3] = data[3] + h*k2_y

            k1_x = data[4]
            k1_y = data[5]
            k2_x = data[4] + h * k1_x / 2
            k2_y = data[5] + h * k1_y / 2
            data[4] = data[4] + h * k2_x
            data[5] = data[5] + h * k2_y


            # pygame.draw.rect(sc, BLACK, (data[0], data[1], 3, 3))
            # pygame.draw.rect(sc, BLACK, (data[2], data[3], 3, 3))

            pygame.draw.rect(sc, BLACK, (data_normal[0]-5, data_normal[1]-5, 10, 10))
            pygame.draw.aaline(sc, PINK, [result_normal[0], result_normal[1]], [data_normal[0], data_normal[1]])
            pygame.draw.aaline(sc, PINK, [result_normal[2], result_normal[3]], [result[0], result[1]])
            pygame.draw.circle(sc, YELLOW, (result_normal[0], result_normal[1]), 20)
            pygame.draw.circle(sc, YELLOW, (result_normal[2], result_normal[3]), 20)
            pygame.draw.rect(sc, BLACK, (data[2], data[3], 3, 3))
            pygame.draw.rect(sc, BLACK, (data[4], data[5], 3, 3))
            pygame.display.update()
        clock.tick(FPS)



def runge_kutta_4(data, n = 10, h = 0.01):
    """
    0
    a21 0
    0 a32 0
    0 0 a43 0
    b1b2 b3 b4"""
    a21 = 1/2
    a32 = 1/2
    a43 = 1
    b1 = 1/6
    b2 = 1/3
    b3 = 1/3
    b4 = 1/6
    sc.fill(WHITE)
    while True:
        for i in pygame.event.get():
            if i.type == pygame.QUIT:
                sys.exit()
        sc.fill(WHITE)
        data_normal = data
        result_normal = spring(data_normal)
        for i in range(2, 10):
            data_normal[i] = result_normal[i - 2]
        for i in range(n):
            result = spring(data)
            for i in range(2, 10):
                data[i] = result[i - 2]
            k1_x = data[2]
            k1_y = data[3]
            k2_x = data[2] + h*a21*k1_x
            k2_y = data[3] + h*a21*k1_y
            k3_x = data[2] + h*a32*k2_x
            k3_y = data[3] + h*a32*k2_y
            k4_x = data[2] + h*a43*k3_x
            k4_y = data[3] + h*a43*k3_y
            data[2] = data[2] + h*(b1*k1_x + b2*k2_x + b3*k3_x + b4*k4_x)
            data[3] = data[3] + h*(b1*k1_y + b2*k2_y + b3*k3_y + b4*k4_y)

            k1_x = data[4]
            k1_y = data[5]
            k2_x = data[4] + h * a21 * k1_x
            k2_y = data[5] + h * a21 * k1_y
            k3_x = data[4] + h * a32 * k2_x
            k3_y = data[5] + h * a32 * k2_y
            k4_x = data[4] + h * a43 * k3_x
            k4_y = data[5] + h * a43 * k3_y
            data[4] = data[4] + h * (b1 * k1_x + b2 * k2_x + b3 * k3_x + b4 * k4_x)
            data[5] = data[5] + h * (b1 * k1_y + b2 * k2_y + b3 * k3_y + b4 * k4_y)


            # pygame.draw.rect(sc, BLACK, (data[0], data[1], 3, 3))
            # pygame.draw.rect(sc, BLACK, (data[2], data[3], 3, 3))

            pygame.draw.rect(sc, BLACK, (data_normal[0]-5, data_normal[1]-5, 10, 10))
            pygame.draw.aaline(sc, PINK, [result_normal[0], result_normal[1]], [data_normal[0], data_normal[1]])
            pygame.draw.aaline(sc, PINK, [result_normal[2], result_normal[3]], [result[0], result[1]])
            pygame.draw.circle(sc, YELLOW, (result_normal[0], result_normal[1]), 20)
            pygame.draw.circle(sc, YELLOW, (result_normal[2], result_normal[3]), 20)
            pygame.draw.rect(sc, BLACK, (data[2], data[3], 3, 3))
            pygame.draw.rect(sc, BLACK, (data[4], data[5], 3, 3))
            pygame.display.update()
        clock.tick(FPS)

#Euler(data=data)
#middle_point(data)
runge_kutta_4(data)
