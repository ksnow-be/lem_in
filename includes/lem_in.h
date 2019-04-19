/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:05:11 by vferry            #+#    #+#             */
/*   Updated: 2019/04/17 16:09:55 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define ANTS_NUM			100
# define ROOM			10000
# define W2				3
# define R				22
# define SCREEN_WIDTH 	1040
# define SCREEN_HEIGHT	880
# define SPRITE_SIZE	64

# include "./../libft/includes/libft.h"
# include "SDL.h"
# include "SDL2_gfxPrimitives.h"

typedef struct		s_ways
{
	int				w;
	int				way[ROOM];
	int				a;
	int				num;
	int				c_ant;
	struct s_ways	*next;
}					t_ways;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				ant;
	int				num_ant;
	char			s_or_e;
	int				weight[2];
}					t_room;

typedef struct		s_sample
{
	t_ways			*way;
	int				count;
	char			ok;
	int				w;
	char			touch[ROOM];
}					t_sample;

typedef struct		s_vis
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		event;
	SDL_Surface		*back_tmp;
	SDL_Texture		*back;
	SDL_Texture		*flag;
	SDL_Texture		*flag_fin;
	SDL_Texture		*ant;
	SDL_Texture		*ant2;
	SDL_Rect		rcbeg;
	int				gameover;
}					t_vis;

typedef	struct		s_lines
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
}					t_lines;

typedef	struct		s_ant
{
	int				num;
	int				x;
	int				y;
	int				shagx;
	int				shagy;
	int				diffx;
	int				diffy;
}					t_ant;

typedef struct		s_move
{
	int				num_ant;
	int				x_dst;
	int				y_dst;
	int				operations;
}					t_move;

typedef struct		s_lem
{
	int				c_ant;
	int				c_room;
	int				c_ways;
	int				c_sample;
	int				r_start;
	int				r_end;
	t_room			rooms[ROOM];
	int				tail[ROOM];
	t_ways			*w_heap;
	t_ways			*w_ready;
	char			**connect;
	int				count_ways;
	int				num_ants;
	int				t;
	t_sample		sample[99999999];
	int				sam;
	int				v;
	t_vis			*vis;
	t_lines			*lines;
	t_ant			ants[ANTS_NUM];
	t_move			move[100][100];
	int				iter;
	int				antgo;
	int				what_bmp;
	char			flag;
}					t_lem;

t_lem				g_inf;

void				init(void);
void				parsing(void);
void				create_con(void);
void				take_con(char *line);
int					check_room(char *str);
void				take_room(char *str, char c, int i);
char				*lem_split(char *line, char c);
int					number(char c);
void				look_way(void);
void				get_ways(void);
void				for_one(void);
int					less_weight(int src);
void				for_one1(void);
void				for_crowd(void);
void				up_tail(t_ways **head, t_ways *cur);
t_ways				*new_way(int from, int weight);
t_ways				*take_tail(t_ways **head);
void				way_built(t_ways *buff);
int					repeat(int *way, int room, int size);
t_ways				*copy_way(t_ways *buff, int room);
void				way_destroy(t_ways *buff);
void				pick(void);
void				try_to_add(int	i, t_ways *buff, int *a, int *t);
void				vote_pick(t_sample *p, int *min, int i);
void				add_start(t_sample *p);
void				put_count(t_sample *p);
void				put_way(t_sample *s, t_ways *buff, int i, int j);
int					diff(t_sample *s, t_ways *buff, int i);
void				walk(void);
void				print(void);
void				ft_clean(char	*str, int i);
void				print_one_way(void);
void				print_crowd(void);
void				print_touch(void);
void				print_opt(void);
void				print_rooms(void);
void				print_tail(void);
void				print_way(void);
void				print_ways();
void				print_pick(void);
void				print_voted(int	a);

void				vizu(void);
int					abs(int num);
int					need_to_move(void);
int					detect_iter(void);
t_ant				same_y(t_ant tmp, int x2, int y2);
t_ant				same_x(t_ant tmp, int x2, int y2);
t_ant				deal_coords(t_ant tmp, int x2, int y2);
t_ant				change_coords(t_ant tmp, int x2, int y2);
void				start_move_ants(int iter);
int					check_algo(int tmp);
void				move_ant(void);
void				draw_ants(void);
void				var1(void);
void				var2(void);
void				var3(void);
t_lines				*correct_line(void);
void				start_draw_line(int i, int j);
void				draw_lines(void);
void				draw_rooms(void);
void				create_textures(void);
void				back_and_in(void);
void				close_sdl(void);
void				vizu(void);
void				bmw(void);
void				coal(void);
void				milo(void);
void				def(void);

#endif
