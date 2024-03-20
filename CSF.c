#include <stdio.h>
#include <stdlib.h>

int *Char_to_Int(char *BeTransed,int length){
	int i = 0;
	int *tmp;
	tmp = calloc(length, sizeof(int));
	for(i = 0;i < length;i++){
		switch (BeTransed[i]){
			case '0':
				*(tmp + i) = BeTransed[i] - '0';
				break;
			case '1':
				*(tmp + i) = BeTransed[i] - '0';
				break;
			case '2':
				*(tmp + i) = BeTransed[i] - '0';
				break;
			case '3':
				*(tmp + i) = BeTransed[i] - '0';
				break;
			case '4':
				*(tmp + i) = BeTransed[i] - '0';
				break;
			case '5':
				*(tmp + i) = BeTransed[i] - '0';
				break;
			case '6':
				*(tmp + i) = BeTransed[i] - '0';
				break;
			case '7':
				*(tmp + i) = BeTransed[i] - '0';
				break;
			case '8':
				*(tmp + i) = BeTransed[i] - '0';
				break;
			case '9':
				*(tmp + i) = BeTransed[i] - '0';
				break;
			case '-':
				*(tmp + i) = BeTransed[i] - 35;
				break;	
		}	
	}
	return tmp;
}

int codeK_check(char *barcode_encoded, int length){
	int i = 0, total_K = 0;
	int n = length - 2;
	int* integer_code;
	integer_code = calloc(length, sizeof(int));
	integer_code = Char_to_Int(barcode_encoded, length);
	/*for(i = 0;i < length;i++){
		printf("%d ", integer_code[i]);
	}*/
	for(i = 0;i < n;i++){
		total_K += ((((n - (i + 2)) % 9) + 1) * integer_code[i]);
	}
	if((total_K % 11) != integer_code[length - 1]){
		return 1;
	}
	else{
		return 2;
	}
}

int codeC_check(char *barcode_encoded, int length){
	int i = 0, total_C = 0;
	int n = length - 2;
	int* integer_code;
	integer_code = calloc(length, sizeof(int));
	integer_code = Char_to_Int(barcode_encoded, length);
	/*for(i = 0;i < length;i++){
		printf("%d ", integer_code[i]);
	}*/
	for(i = 0;i < n;i++){
		total_C += ((((n - (i + 1)) % 10) + 1) * integer_code[i]);
	}
	if((total_C % 11) != integer_code[length - 2]){
		return 1;
	}
	else{
		return 2;
	}
}

char *encode(int *list, int number){
	int i = 0;
	int code_length = (number - 11) / 6;				
	char *barcode_temp;
	int Number_of_digit = 0;
	barcode_temp = calloc(code_length, sizeof(char));
	for(i = 5;i < number;i++){
		if(i == number - 6){
			return barcode_temp;
		}
		else{
			if(list[i + 1] == 0){
				if(list[i + 2] == 0){
					if(list[i + 3] == 0){
						if(list[i + 4] == 0){
							if(list[i + 5] == 0){
								return "bad code";
								break;
							}
							else if(list[i + 5] == 1){
								*(barcode_temp + Number_of_digit) = '9';
								Number_of_digit++;
								i += 5;
							}
						}
						else if(list[i + 4] == 1){
							if(list[i + 5] == 0){
								return "bad code";
								break;
							}
							else if(list[i + 5] == 1){
								*(barcode_temp + Number_of_digit) = '2';
								Number_of_digit++;
								i += 5;
							}
						}
					}
					else if(list[i + 3] == 1){
						if(list[i + 4] == 0){
							if(list[i + 5] == 0){
								*(barcode_temp + Number_of_digit) = '-';
								Number_of_digit++;
								i += 5;
							}
							else if(list[i + 5] == 1){
								*(barcode_temp + Number_of_digit) = '6';
								Number_of_digit++;
								i += 5;
							}
						}
						else if(list[i + 4] == 1){
							if(list[i + 5] == 0){
								return "bad code";
								break;
							}
							else if(list[i + 5] == 1){
								return "bad code";
								break;
							}
						}
					}
				}
				else if(list[i + 2] == 1){
					if(list[i + 3] == 0){
						if(list[i + 4] == 0){
							if(list[i + 5] == 0){
								return "bad code";
								break;
							}
							else if(list[i + 5] == 1){
								*(barcode_temp + Number_of_digit) = '7';
								Number_of_digit++;
								i += 5;
							}
						}
						else if(list[i + 4] == 1){
							if(list[i + 5] == 0){
								return "bad code";
								break;
							}
							else if(list[i + 5] == 1){
								return "bad code";
								break;
							}
						}
					}
					else if(list[i + 3] == 1){
						if(list[i + 4] == 0){
							if(list[i + 5] == 0){
								*(barcode_temp + Number_of_digit) = '4';
								Number_of_digit++;
								i += 5;
							}
							else if(list[i + 5] == 1){
								return "bad code";
								break;
							}
						}
						else if(list[i + 4] == 1){
							if(list[i + 5] == 0){
								return "bad code";
								break;
							}
							else if(list[i + 5] == 1){
								return "bad code";
								break;
							}
						}
					}
				}
			}
			else if(list[i + 1] == 1){
				if(list[i + 2] == 0){
					if(list[i + 3] == 0){
						if(list[i + 4] == 0){
							if(list[i + 5] == 0){
								*(barcode_temp + Number_of_digit) = '0';
								Number_of_digit++;
								i += 5;
							}
							else if(list[i + 5] == 1){
								*(barcode_temp + Number_of_digit) = '8';
								Number_of_digit++;
								i += 5;
							}
						}
						else if(list[i + 4] == 1){
							if(list[i + 5] == 0){
								*(barcode_temp + Number_of_digit) = '1';
								Number_of_digit++;
								i += 5;
							}
							else if(list[i + 5] == 1){
								return "bad code";
								break;
							}
						}
					}
					else if(list[i + 3] == 1){
						if(list[i + 4] == 0){
							if(list[i + 5] == 0){
								*(barcode_temp + Number_of_digit) = '3';
								Number_of_digit++;
								i += 5;
							}
							else if(list[i + 5] == 1){
								return "bad code";
								break;
							}
						}
						else if(list[i + 4] == 1){
							if(list[i + 5] == 0){
								return "bad code";
								break;
							}
							else if(list[i + 5] == 1){
								return "bad code";
								break;
							}
						}
					}
				}
				else if(list[i + 2] == 1){
					if(list[i + 3] == 0){
						if(list[i + 4] == 0){
							if(list[i + 5] == 0){
								*(barcode_temp + Number_of_digit) = '5';
								Number_of_digit++;
								i += 5;
							}
							else if(list[i + 5] == 1){
								return "bad code";
								break;
							}
						}
						else if(list[i + 4] == 1){
							if(list[i + 5] == 0){
								return "bad code";
								break;
							}
							else if(list[i + 5] == 1){
								return "bad code";
								break;
							}
						}
					}
					else if(list[i + 3] == 1){
						if(list[i + 4] == 0){
							if(list[i + 5] == 0){
								return "bad code";
								break;
							}
							else if(list[i + 5] == 1){
								return "bad code";
								break;
							}
						}
						else if(list[i + 4] == 1){
							if(list[i + 5] == 0){
								return "bad code";
								break;
							}
							else if(list[i + 5] == 1){
								return "bad code";
								break;
							}
						}
					}
				}
			}
		}
	}
}

int front_or_back(int *list, int number){
	int i = 0, front_check = 0, back_check = 0;
	int startCommand_check[5] = {0,0,1,1,0};
	int *rev;
	rev = (int *)malloc(sizeof(int) * number);
	for(i = 0;i < number;i++){
		*(rev + i) = list[number - i - 1];
	}
	for(i = 0;i < 5;i++){
		if(list[i] == startCommand_check[i]){
			front_check++;
		}
		if(rev[i] == startCommand_check[i]){
			back_check++;
		}
	}
	if(front_check == 5){
		return 1;
	}
	else if(back_check == 5){
		return 2;
	}
	else{
		return -1;
	}
}

int Digit_Check(int *list, int number){
	int i = 0;
    int zero1 = list[0];
    int zero2 = list[number - 1];
    int zero = (zero1 + zero2) / 2;
    int one = zero * 2;
    int digit = 0, check = 0;
    for(i = 0; i < number; i++) {
       digit = list[i];
       if(((digit <= zero*1.05) && (digit >= zero*0.95)) || ((digit <= one*1.05) && (digit >= one*0.95))) {
           check++;
       }
       else {
           return -1;
       }
    }
    if(check == number) {
        return 1;
    }
}

int is_valid(int* list, int number) {
	int i = 0;
	for(i = 0;i < number;i++){
		if(list[i] < 1 || list[i] > 200){
			return 2;
		}
	}
	return 1;
}

int main(){
    FILE *file;
    int i = 0;
    int inputData = 0;
    int input_case_number = 0;
    int *inputData_list;
    int *reverse_list;
    int *trashcan;
    char *barcode;
    file = fopen("test.txt", "r");
    if((file == NULL)){
    	printf("File can not be opened.\n");
    	return 0;
	}
	else{
        fscanf(file, "%d", &input_case_number);
        if(input_case_number > 150){
        	printf("bad code\n");
        	trashcan = calloc(input_case_number,sizeof(int));
        	for(i = 0;i < input_case_number;i++){
        		fscanf(file,"%d", &inputData);
        		*(trashcan + i) = inputData;
			}
		}
		else{
			if((input_case_number - 11) % 6 != 0){
				printf("bad code\n");
				trashcan = calloc(input_case_number,sizeof(int));
        		for(i = 0;i < input_case_number;i++){
        			fscanf(file,"%d", &inputData);
        			*(trashcan + i) = inputData;
				}
			}
			else{
		        while(input_case_number > 0) {
		        	int code_length = (input_case_number - 11) / 6;
		        	barcode = calloc(code_length, sizeof(char));
					reverse_list = calloc(input_case_number, sizeof(int));
		       		inputData_list = calloc(input_case_number, sizeof(int));
		            for(i = 0; i < input_case_number; i++) {
		                fscanf(file, "%d", &inputData);
		                *(inputData_list + i) = inputData;
		            }
		            /*for(i = 0;i < input_case_number; i++){
		            	printf("%d\n", inputData_list[i]);
					}*/
					if(is_valid(inputData_list, input_case_number) == 2) {
		            	printf("bad code\n");
					} 
					else{
						if(Digit_Check(inputData_list, input_case_number) < 0) {
		                	printf("bad code\n");
		            	}
			            else{
			                float zero1 = inputData_list[0];
			                float zero2 = inputData_list[input_case_number - 1];
			                float zero = (zero1 + zero2) / 2;
			                for(i = 0; i < input_case_number; i++) {
			                    if(inputData_list[i] / zero > 1.5) {
			                        inputData_list[i] = 1; 
			                    }
			                    else{
			                        inputData_list[i] = 0;
			                    }
			                }
			                /*for(i = 0;i < input_case_number;i++){
			                	printf("%d ", inputData_list[i]);
							}*/
							if(front_or_back(inputData_list, input_case_number) == 1){
								barcode = encode(inputData_list, input_case_number);
								if(strcmp(barcode, "bad code") == 0){
									printf("bad code\n");
								}
								else if(codeC_check(barcode, code_length) == 1){
									printf("bad C\n");
								}
								else if(codeK_check(barcode, code_length) == 1){
									printf("bad K\n");
								}
								else{
									for(i = 0;i < code_length - 2;i++){
										printf("%c", barcode[i]);
									}
									printf("\n");
								}
							}
							else if(front_or_back(inputData_list, input_case_number) == 2){
								for(i = 0;i < input_case_number;i++){
									*(reverse_list + i) = inputData_list[input_case_number - i - 1];
								}
								/*for(i = 0;i < input_case_number;i++){
			                		printf("%d ", reverse_list[i]);
								}*/
								barcode = encode(reverse_list, input_case_number);
								if(strcmp(barcode, "bad code") == 0){
									printf("bad code\n");
								}
								else if(codeC_check(barcode, code_length) == 1){
									printf("bad C\n");
								}
								else if(codeK_check(barcode, code_length) == 1){
									printf("bad K\n");
								}
								else{
									for(i = 0;i < code_length - 2;i++){
										printf("%c", barcode[i]);
									}
									printf("\n");
								}
							}
							else{
								printf("bad code\n");
							}
				        }
					}
			        fscanf(file, "%d", &input_case_number);
			    }
			}
			free(trashcan);
			free(barcode);
    		free(inputData_list);
   			free(reverse_list);
		}
    }
    fclose(file);
    return 0;
}


