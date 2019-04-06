all: clean juego inventory_test link_test player_test space_test dist

CCFlags = -Wall -pedantic -ansi -g

#Tests
inventory_test: inventory_test.o inventory.o set.o
	gcc -o inventory_test inventory_test.o inventory.o set.o
link_test: link_test.o link.o
	gcc -o link_test link_test.o link.o
player_test: player_test.o player.o space.o inventory.o object.o link.o set.o
	gcc -o player_test player_test.o player.o space.o inventory.o object.o link.o set.o
space_test: space_test.o space.o object.o set.o link.o
	gcc -o space_test space_test.o space.o object.o set.o link.o
object_test: object_test.o object.o set.o
	gcc -o object_test object_test.o object.o set.o


#Programa Principal
juego: game_loop.o space.o game.o command.o player.o object.o GameReader.o die.o set.o inventory.o link.o 
	gcc -o juego game_loop.o space.o game.o command.o player.o object.o GameReader.o die.o set.o inventory.o link.o
game_loop.o: game_loop.c game.h
	gcc $(CCFlags) -c game_loop.c
space.o: space.c space.h object.h set.h link.h
	gcc $(CCFlags) -c space.c
game.o: game.c game.h GameReader.h player.h command.h die.h
	gcc $(CCFlags) -c game.c
command.o: command.c command.h types.h
	gcc $(CCFlags) -c command.c
player.o: player.c player.h space.h inventory.h
	gcc $(CCFlags) -c player.c
object.o: object.c object.h types.h
	gcc $(CCFlags) -c object.c
GameReader.o: GameReader.c GameReader.h space.h game.h
	gcc $(CCFlags) -c GameReader.c
die.o: die.c die.h types.h object.h
	gcc $(CCFLAGS) -c die.c
set.o: set.c set.h types.h
	gcc $(CCFLAGS) -c set.c
inventory.o: inventory.c inventory.h types.h
	gcc $(CCFLAGS) -c inventory.c
link.o: link.c link.h types.h
	gcc $(CCFLAGS) -c link.c

dist:
	tar -cvzf i3_Maria_Lucia_Andres_Francisco.tgz *c *h makefile *dat

clean: 
	rm -rf *.o juego inventory_test link_test player_test space_test *.tgz
