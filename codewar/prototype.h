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
void setStack(CPU * cpu);
int get_file_size(char * file);

/* File init */
int init(CPU * grid);
void setMem(CPU * cpu);
void setReg(CPU * cpu);

/* File random */
int randomCPU();
color randomColor();

/* File extract */
word extract(CPU * cpu);

/* File execute */
void next();
void decryte(word * result, CPU * cpu);

word instructionName(word * wrd);
word instructionType(word wrd);
word instructionValue(word wrd);
word instructionType2(word wrd);
word instructionValue2(word wrd);
word instructionMoveType(word wrd);
word instructionMoveValue(word wrd);
word instructionMoveType2(word wrd);
word instructionMoveValue2(word wrd);

/* File shell */
void display_prompt();
void run_commande(CPU * grid);

/* File instruction */
int get_value(CPU * cpu, operande op);
void addressing(CPU * cpu, operande op, int value);

void move(CPU * cpu, operande op1, operande op2);
void add(CPU * cpu, operande op1, operande op2);
void push(CPU * cpu, operande op);
void pop(CPU * cpu, operande op);
void substract(CPU * cpu, operande op1, operande op2);

void commande(char ** tab, CPU * grid, int pid);
int kill(int pid, int sig);
