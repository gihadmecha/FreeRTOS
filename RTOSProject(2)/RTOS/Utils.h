
#ifndef UTILS_H_
#define UTILS_H_

#define  CLR_BIT(reg,bit)   (reg=reg&~(1<<bit))
#define  SET_BIT(reg,bit)   (reg=reg|(1<<bit))
#define  TOG_BIT(reg,bit)   (reg=reg^(1<<bit))
#define  READ_BIT(reg,bit)   ((reg>>bit)&1)



#endif /* UTILS_H_ */