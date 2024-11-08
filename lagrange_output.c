void graphOutputLagrange(double x[N], double y_c[N], double y_exp[N]){
    FILE *gnuplot = popen("gnuplot", "w");
    if (!gnuplot)
    {
        perror("popen");
        exit(EXIT_FAILURE);
    }
    
    fprintf(gnuplot, "set terminal png\n");
    fprintf(gnuplot, "set output './graphics/Lagrange.png'\n");
    //название общего графика
    fprintf(gnuplot, "set title 'График полинома Лагранжа и экспериментальные точки'\n");

    fprintf(gnuplot, "set xlabel 'x'\nset ylabel 'y' rotate by 0\n");
    fprintf(gnuplot, "plot '-' u 1:2 w l t 'Лагранж', '' w p pt 7 pointsize 1.5, '-' u 1:2 w p t 'Экспериментальные'\n");
    //построение полинома Лагранжа 2-ой степени
    for (int i = 0; i < N; i++)
    {
        fprintf(gnuplot, "%f %f\n", x[i], y_c[i]);
    }
    fprintf(gnuplot, "e\n");

    //исходные точки, которые были использованы для расчета полинома 2-ой степени
    for (int i = 0; i < N; i += 5)
    {
        fprintf(gnuplot, "%f %f\n", x[i], y_c[i]);
    }
    fprintf(gnuplot, "e\n");

    //построение точек экспериментальных данных
    for (int i = 0; i < N; i++)
    {
        fprintf(gnuplot, "%f %f\n", x[i], y_exp[i]);
    }
    fprintf(gnuplot, "e\n");

    fflush(gnuplot);
    pclose(gnuplot);
    fflush(gnuplot);
    //exit(EXIT_SUCCESS);
}
