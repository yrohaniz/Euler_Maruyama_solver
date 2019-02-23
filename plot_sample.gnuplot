set terminal postscript eps color enhanced "Times-Roman" 24
set output "sample_path.eps"
set size 2.2,2.2
set title 'Sample path for the Ito process X satisfying dX=aXdt+bXdW obtained using Euler-Maruyama scheme'
set xrange [0:60]
set xlabel "t"
set ylabel "X_t" 
set yrange [-10:10]
set style line 1 lt 1 lw 2 lc rgb"blue"
plot 'cmake-build-debug/Sample_solution' u 1:2 w l ls 1 notitle
