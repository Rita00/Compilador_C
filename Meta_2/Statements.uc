int main(void){
;;;
{};
{a=1;};
{{};a=1;{};};
{a=1;b=2;}
{{};a=1;{};b=2;{};}
{a=1;b=2;c=3;{};d=4;e=5;}
if (1){};
if (2){}else{};
if (3){a=1;}else{};
if (4){a=1;b=2;}else{};
if (5){a=1;}else{c=3;};
if (6){a=1;b=2;}else{c=3;d=4;};
if (7){}else{a=1;}
if (8){}else{a=1;b=2;}
while (1){}
while (2){a=1;}
return;
return 2;
a1(1);
a2(1,2);
a3(1,2,3);
printf('\n');
}