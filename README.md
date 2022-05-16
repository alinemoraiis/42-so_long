# 42-so_long
- This project is about coding a basic 2D game using the school (42 Lisboa) graphical library: MiniLibX. The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.

## :video_game: Folders
- **[ft_printf](https://github.com/alinemoraiis/42-so_long/tree/master/ft_printf)**: this folder contains all functions from project [42-ft_printf](https://github.com/alinemoraiis/42-ft_printf) - The ft_printf() is a mimic of the original printf(), but handle only the following conversions: cspdiuxX%.
- **[get_next_line](https://github.com/alinemoraiis/42-so_long/tree/master/get_next_line)**: this folder contains all functions from project [42-get_next_line](https://github.com/alinemoraiis/42-get_next_line) - The get_next_line() is a function that allow you read a text file pointed to by the file descriptor and return one line at a time.
- **[images](https://github.com/alinemoraiis/42-so_long/tree/master/images)**: this folder contains all .xpm files (images) used in the game.
- **[maps](https://github.com/alinemoraiis/42-so_long/tree/master/maps)**: this folder contains some .ber files (maps) examples used to test and run the game.

## :video_game: Files / Functions
- **[Makefile](https://github.com/alinemoraiis/42-so_long/blob/master/Makefile)**: defines set of tasks (compile all functions) to be executed.
- **[ft_itoa.c](https://github.com/alinemoraiis/42-so_long/blob/master/ft_itoa.c)**: allocates memory and convert the int received as an argument to string.
- **[game_bonus.c](https://github.com/alinemoraiis/42-so_long/blob/master/game_bonus.c)**: function to print player's movements in the screen (Bonus part).
- **[init_game.c](https://github.com/alinemoraiis/42-so_long/blob/master/init_game.c)**: the functions in this file is used to start the game. *read_images* will read all .xpm files from [images](https://github.com/alinemoraiis/42-so_long/tree/master/images) folder; *set_background* will print a background for the game; *set_components* will check each component of the .ber file and print the correspondent image; *init_game* is the main function of this file, it init some counters, read the .ber file and call for the necessaries functions.
- **[libft_utils.c](https://github.com/alinemoraiis/42-so_long/blob/master/libft_utils.c)**: this file has two functions from libft project. *ft_strrchr* locates the last occurrence of c in the string s and return a pointer to the located character; *ft_strncmp* compare, not more than n characters in the strings s1 and s2.
- **[main.c](https://github.com/alinemoraiis/42-so_long/blob/master/main.c)**: is the first function executed when the game is started.
- **[move_player.c](https://github.com/alinemoraiis/42-so_long/blob/master/move_player.c)**: everytime that you need to move the player, the functions from this file are called. *move_player* check which key (up, down, left, right) the user is pressing and call the respective function to move the character; *render_components* everytime that the player is moved, the components need to be renderized. *render_game* read the iamges, read the file .ber and call the render_components function; *key_hook* receive which keycode the user is pressing.
- **[moves.c](https://github.com/alinemoraiis/42-so_long/blob/master/moves.c)**: move the character and save the new position. *move_right* do the calculation to move to right; *move_left* do the calculation to move to left; *move_down* do the calculation to move down; *move_up* do the calculation to move up; *close_game* function to close the game and free allocated memory.
- **[open_window/c](https://github.com/alinemoraiis/42-so_long/blob/master/open_window.c)**: functions to read and calculate the size of the map. *read_map* function to read the .ber file; *get_width* function to calculate the width of the window; *error_game* print an error in the screen about if the map is not retangular; *get_height* calculate the height of the window; *open_window* main function of this file. Call the other functions and open a new window.
- **[put_image.c](https://github.com/alinemoraiis/42-so_long/blob/master/put_image.c)**: function to print the image in the window.
- **[read_images.c](https://github.com/alinemoraiis/42-so_long/blob/master/read_images.c)**: read all .xpm files from [images](https://github.com/alinemoraiis/42-so_long/tree/master/images) folder. *read_wall* read the image correspondent to the wall; *read_coin* read the image correspondent to the coin; *read_player* read the image correspondent to the player; *read_background* read the image correspondent to the free spaces (background); *read_exit* read the images correspondent to the exit.
- **[so_long.h](https://github.com/alinemoraiis/42-so_long/blob/master/so_long.h)**: header file with all declarated functions, libraries, structs and variables.
- **[valid_map.c](https://github.com/alinemoraiis/42-so_long/blob/master/valid_map.c)**: the functions in this file are used to valid if the .ber file has all components necessary to execute the game. *check_components* check if there is at least one coin, one wall, one exit and one player; *count_components* read the .ber file and count all components; *check_border* validate if the map is surrounded by walls; *valid_map* main function of this file. Calls the other functions and initialize the counters. 

## :video_game: Useful Links
- **[MiniLibX Doc](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html)**