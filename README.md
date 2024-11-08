# FdF

`FdF` is short for ’fil de fer’ in French which means ’wireframe model’.

![image](https://github.com/user-attachments/assets/b5a85041-35fc-47ee-8b41-5680bf972f80)

## Compile your program with the library:

For: MacOS

```
$(CC) -g $(OBJS) -L$(MLX_DIR) -lmlx42 -L$(LIBFT_DIR) -lft -lm -lz -lglfw -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -o $(NAME)
```
Modify the Makefile file

And then

```
make all

./fdf maps/42.fdf
```

```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

Parse the above map file and render it in a 3D model

![image](https://github.com/user-attachments/assets/0d64fdc5-b133-4cb9-bb33-4eeb9876650d)
