/* FIle displayGrid */
void display_grid(CPU ** grid);
void free2(char ** line);
color get_color(CPU * cpu);
int cmp_color(color color_cpu);

/* File displayCPU */
void displayCPU(CPU cpu);
void displayReg(CPU cpu);

/* Load */
int open_load_File(char * file, CPU * cpu);

/* File init */
int init(CPU * grid);
void setMem(CPU * cpu);
void setReg(CPU * cpu);

/* File Random */
CPU randomCPU(CPU * grid);
color randomColor();