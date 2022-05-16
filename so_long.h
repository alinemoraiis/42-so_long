/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ados-rei <ados-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:34:15 by ados-rei          #+#    #+#             */
/*   Updated: 2022/05/12 17:05:05 by ados-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

//# define malloc(x) NULL

# define BUFFER_SIZE	500

typedef struct s_map {
	int	empty_space;
	int	wall;
	int	banana;
	int	exit;
	int	player;
	int	other;
	int	lines;
}	t_map;

typedef struct s_game {
	void	*mlx;
	void	*win;
	char	*map_file;
	int		total_coins;
	int		width;
	int		height;
	void	*wall;
	void	*coin;
	void	*player;
	void	*exit_open;
	void	*exit_close;
	void	*background;
	int		player_position;
	int		player_line;
	int		coins;
	int		movements;
	int		keycode;
}	t_game;

/*open_window*/
char	*read_map(char *file);
int		get_width(t_game *game);
void	error_game(t_game *game);
int		get_height(t_game *game);
char	*open_window(t_game *game);

/*read_images*/
void	read_wall(t_game *game);
void	read_coin(t_game *game);
void	read_player(t_game *game);
void	read_background(t_game *game);
void	read_exit(t_game *game);

/*init_game*/
void	read_images(t_game *game);
void	set_background(t_game *game);
void	set_components(t_game *game, char map_file_cont,
			int position, int line);
void	init_game(t_game *game);

/*move_player*/
void	move_player(t_game *game);
void	render_components(t_game *game, char map_file_cont, int position,
			int line);
void	render_game(t_game *game);
int		key_hook(int keycode, t_game *game);

/*moves*/
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_up(t_game *game);
int		close_game(t_game *game);

/*get_next_line*/
char	*read_file(int fd, char *file);
char	*get_line(char *file);
char	*save_file(char *file);
char	*get_next_line(int fd);

/*valid_map*/
int		check_components(t_map *map);
void	count_components(t_game *game, t_map *map);
int		check_border(t_game *game, t_map *map);
void	valid_map(t_game *game);

/*put_image*/
void	put_image(t_game *game, int position, int line);

/*ft_itoa*/
char	*ft_itoa(int n);

/*game_bonus*/
void	print_movement(t_game *game);

/*get_next_line_utils*/
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*ft_printf*/
int		ft_printf(const char *str, ...);
int		ft_print_char(int c);
int		ft_print_str(char *s);
int		ft_print_ptr(unsigned long p);
int		ft_print_nbr(int d);
int		ft_print_uns(unsigned int u);
int		ft_print_hex(unsigned int x, char format);
void	ft_putnbr_fd(int n, int fd);

/*libft_utils*/
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
