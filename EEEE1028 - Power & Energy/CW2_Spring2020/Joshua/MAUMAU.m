y=[29.7328 29.6448 29.4702 28.9585];
x=[0.7433 0.9882 1.4735 2.8958]
x1=0.7433;
x2=2.8958;
y1=29.7328;
y2=28.9585;
m=(y2-y1)/(x2-x1);
plot(x,y);
title('Graph of Vs against Is') 
ylabel('Secondary Voltage, Vs') % label for y axis
xlabel('Secondary Current, Is') % label for x axis
fprintf("m=%f",m);