function test(x, y, y2, y3, name)
  close all
  plot (x, y);
  hold on
  plot (x, y, 'r*'); % plot red stars for all the data points
  plot (x, y2);
  plot (x, y3);
  title('testing', 'FontSize', 24)
  xlabel('x axis', 'FontSize', 24)
  ylabel('y axis', 'FontSize', 24)
  saveas(gcf, name);
  end
