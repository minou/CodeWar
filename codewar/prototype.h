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
void next(CPU * cpu);

/* File execute */
void next(CPU * cpu);
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

/* File instruction */
void move(operande op1, operande op2);

/* File shell */
void display_prompt();
void run_commande(CPU * grid);
void commande(char ** tab, CPU * grid);
