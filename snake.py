
import curses
import time
from random import randint
########################################

class Snake(object):
    def __init__(self, yx):
        #dir: 0 - N, 1 - E, 2 - S, 3 - W
        self.x = yx[1]/2
        self.y = yx[0]/2
        self.dir = 1
        self.size = 1
        self.tab = [[self.y, self.x]]

    def head(self):
        return self.tab[0]

    def x(self):
        self.tab[0][1]

    def y(self):
        return int(self.tab[0][0])

    def draw(self):
        screen.addstr(int (self.tab[0][0]) , int (self.tab[0][1]), '@', curses.A_BOLD)
        for i in range( len (self.tab)):
            screen.addstr(int (self.tab[i][0]) ,int (self.tab[i][1]), '@')

    def turn_head(self, d):
        if d == (self.dir + 1) % 4 or d == (self.dir - 1) % 4:
            self.dir = d
        else:
            return False

    def bite(self):
        if self.tab[0] in self.tab[1::]:
            return True
        else:
            return False

    def debug(self):
        screen.addstr( 12, 12, '{0}, {1}'.format(self.tab[0][1], self.tab[0][0]) )
        screen.addstr( 13, 12, str(self.size) )


    def grow(self):
        self.tab.insert(0, [self.tab[0][0], self.tab[0][1]] )
        self.size += 1

    def move(self):
        self.tab.insert(0, [self.tab[0][0], self.tab[0][1]] )
        self.tab.pop()
        if self.dir == 0: self.tab[0][0] -= 1
        elif self.dir == 1: self.tab[0][1] += 1
        elif self.dir == 2: self.tab[0][0] += 1
        elif self.dir == 3: self.tab[0][1] -= 1

########################################

class Snack(object):
    def __init__(x, y):
        self.x = x
        self.y = y

    def loc(self):
        return [self.y, self.x]

    def remove(self):
        screen.addstr(int(self.y), int(self.x), '.')

########################################

def draw_scene(yx):
    for y in range(yx[0] - 2):
        screen.addstr(y, 0, '#')
        screen.addstr(y, yx[1] - 10, '#')
    for x in range(yx[1] - 10):
        screen.addstr(0, x, '#')
        screen.addstr(yx[0] - 2, x, '#')

def spawn_food(yx, snacks):
    x, y = randint(1, yx[0] - 11)
    snacks.append(Snack(x, y))
    screen.addstr(y, x, '*')

def event_manager(Snake, Snack, snacks):
    if (Snake.head() == Snack.loc()):
        points += 50
        Snack.remove()

def check_lose(yx, Snake):
    if Snake.bite() == True: return True
    if Snake.tab[0][1] == yx[1] - 10 and Snake.dir == 1: return True
    if Snake.tab[0][1] == 0 and Snake.dir == 3: return True
    if Snake.tab[0][0] == yx[0] - 2 and Snake.dir == 2: return True
    if Snake.tab[0][0] == 0 and Snake.dir == 0: return True
    else: return False

def key_manager(key, Snake):
    if key == ord('w'): Snake.turn_head(int(0))
    if key == ord('s'): Snake.turn_head(int(2))
    if key == ord('a'): Snake.turn_head(int(3))
    if key == ord('d'): Snake.turn_head(int(1))
    #
    if key == ord('b'): Snake.grow()
    #

########################################

#MAIN
screen = curses.initscr()
curses.noecho()
yx = screen.getmaxyx()
draw_scene(yx)

snacks = []
key = 'something'
points = 0
Bart = Snake(yx)

Bart.draw()

while( key != ord('p')):
    key = screen.getch()
    key_manager(key, Bart)
    Bart.move()
    screen.clear()
    draw_scene(yx)
    Bart.draw()
    Bart.debug()
    screen.refresh()
    if(check_lose(yx, Bart) == True): break


curses.endwin()
#END OF MAIN
