
import curses
import time
from random import randint
########################################

class Snake(object):
    def __init__(self, yx):
        #dir: 0 - N, 1 - E, 2 - S, 3 - W
        self.x = yx[1]/2
        self.y = yx[0]/2
        self.just_eaten = False
        self.dir = 1
        self.size = 1
        self.tab = [[self.y, self.x]]

    def head(self):
        return self.tab[0]

    def draw(self):
        screen.addstr(int (self.tab[0][0]) , int (self.tab[0][1]), '@', curses.A_BOLD)
        for i in range(1,  len (self.tab)):
            screen.addstr(int (self.tab[i][0]), int (self.tab[i][1]), '@')

    def turn_head(self, d):
        if d == (self.dir + 1) % 4 or d == (self.dir - 1) % 4:
            self.dir = d
        else:
            return False

    def bite(self):
        if self.tab[0] in self.tab[1::]:
            if self.just_eaten == False:
                return True
        else:
            return False

    def grow(self):
        self.tab.insert(0, [self.tab[0][0], self.tab[0][1]] )
        self.size += 1
        self.just_eaten = True

    def move(self):
        self.just_eaten = False
        self.tab.insert(0, [self.tab[0][0], self.tab[0][1]] )
        self.tab.pop()
        if self.dir == 0: self.tab[0][0] -= 1
        elif self.dir == 1: self.tab[0][1] += 1
        elif self.dir == 2: self.tab[0][0] += 1
        elif self.dir == 3: self.tab[0][1] -= 1

    def debug(self):
        screen.addstr( 1, 1, '{0}, {1}'.format(self.tab[0][1], self.tab[0][0] ) )
        screen.addstr( 2, 1, str(self.size) )



########################################

class Snack(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.type = 1

    def loc(self):
        return (self.y, self.x)

########################################

def spawn_food(yx, snacks):
    x = randint(1, yx[1] - 1)
    y = randint(1, yx[0] - 1)
    snacks.append(Snack(x, y))

def snacks_manager(Snake, snacks):
    shy, shx = Snake.head()
    for Snack in snacks:
        y, x = Snack.loc()
        screen.addstr(y, x, '*')
        if shy == y and shx == x:
            Snake.grow()
            snacks.remove(Snack)

def draw_scene(yx):
    for y in range(yx[0]):
        screen.addstr(y, 0, '#')
        screen.addstr(y, yx[1], '#')
    for x in range(yx[1]):
        screen.addstr(0, x, '#')
        screen.addstr(yx[0], x, '#')

def check_lose(yx, Snake):
    if Snake.bite() == True: return True
    if Snake.tab[0][1] == yx[1] and Snake.dir == 1: return True
    if Snake.tab[0][1] == 0 and Snake.dir == 3: return True
    if Snake.tab[0][0] == yx[0] and Snake.dir == 2: return True
    if Snake.tab[0][0] == 0 and Snake.dir == 0: return True
    else: return False

def key_manager(key, Snake, yx, snacks):
    if key == ord('w'): Snake.turn_head(0)
    if key == ord('s'): Snake.turn_head(2)
    if key == ord('a'): Snake.turn_head(3)
    if key == ord('d'): Snake.turn_head(1)
    #
    if key == ord('g'): Snake.grow()
    if key == ord('b'): spawn_food(yx, snacks)
    #

def menu(yx):
    tab = [' ', ' ', ' ']
    key = 'something'
    foo = 0
    while (key != ord('d')):
        screen.clear()
        for i in range( len(tab) ):
            if i == foo: tab[i] = '>'
            else: tab[i] = ' '
        screen.addstr(int (yx[0] / 2 - 1), int (yx[1] / 2 - 2) , '{0} Play'.format (tab[0]) )
        screen.addstr(int (yx[0] / 2), int (yx[1] / 2 - 2) , '{0} Options'.format (tab[1]) )
        screen.addstr(int (yx[0] / 2 + 1), int (yx[1] / 2 - 2), '{0} Exit'.format (tab[2]) )
        screen.move(yx[0], yx[1])
        key = screen.getch()
        if key == ord('w'):
            foo = (foo + 2) % 3
        if key == ord('s'):
            foo = (foo + 1) % 3
    if foo == 0: return True
    elif foo == 1: options(yx)
    elif foo == 2: return False

def options(yx):
    screen.clear()
    screen.addstr(int (yx[0] / 2), int (yx[1] / 2 - 2), 'JESTEM W OPCJACH')
    key = screen.getch()
    menu(yx)


########################################

#MAIN
# init screen, draw sceene
screen = curses.initscr()
curses.noecho()
#curses.cbreak()

yx = screen.getmaxyx()
yx = (yx[0] - 2, yx[1] - 20)
draw_scene(yx)

# init game variables
lost = False
snacks = []
key = 'something'
points = 0
Bart = Snake(yx)

Bart.draw()
Bart.grow()

if menu(yx) == True:
    curses.halfdelay(5)

    while not lost:
        key = screen.getch()

        key_manager(key, Bart, yx, snacks)
        Bart.move()
        screen.clear()
        draw_scene(yx)
        snacks_manager(Bart, snacks)
        Bart.debug()
        Bart.draw()
        screen.move(yx[0], yx[1])
        screen.refresh()
        if(check_lose(yx, Bart) == True): lost = True

curses.endwin()
#END OF MAIN
