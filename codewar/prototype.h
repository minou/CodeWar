/* FIle displayGrid */
void display_grid(CPU * grid);
color get_color(CPU * cpu);
int cmp_color(color color_cpu);

/* File displayCPU */
void displayCPU(CPU cpu);
void displayReg(CPU cpu);

/* open_load */
int open_load_File(char * file, CPU * cpu);
void setColor(CPU * cpu, color color_cpu);

/* File init */
int init(CPU * grid);
void setMem(CPU * cpu);
void setReg(CPU * cpu);

/* File random */
int randomCPU();
color randomColor();

/* File extract */
word extract(CPU * cpu, int num);
word switching(word word);
void next(CPU * cpu);
