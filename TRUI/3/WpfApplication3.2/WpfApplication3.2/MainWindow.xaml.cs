using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApplication3._2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Pick_Color(object sender, RoutedEventArgs e)
        {
            if (canvas_item == null)
                return;
            string tag = ((Control)sender).Tag.ToString();
            Color color = (Color)ColorConverter.ConvertFromString(tag);
            canvas_item.DefaultDrawingAttributes.Color = color;
            //ChangeColor(canvas_item, color);
        }

        void ChangeColor(InkCanvas inkCanvas, Color color)
        {
            foreach (var stroke in inkCanvas.Strokes)
            {
                stroke.DrawingAttributes.Color = color;
            }
        }

        private void Mode_Checked(object sender, RoutedEventArgs e)
        {
            if (canvas_item == null)
                return;

            if (ink_mode.IsChecked == true)
            {
                canvas_item.EditingMode = InkCanvasEditingMode.Ink;
            }
            else if (select_mode.IsChecked == true)
            {
                canvas_item.EditingMode = InkCanvasEditingMode.Select;
            }
            else if (eraseByPoint_mode.IsChecked == true)
            {
                canvas_item.EditingMode = InkCanvasEditingMode.EraseByPoint;
            }
            else if (eraseByStroke_mode.IsChecked == true)
            {
                canvas_item.EditingMode = InkCanvasEditingMode.EraseByStroke;
            }
        }

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            if (canvas_item == null)
                return;

            var value = ((Slider)sender).Value;
            canvas_item.DefaultDrawingAttributes.Width = value;
            canvas_item.DefaultDrawingAttributes.Height = value;
        }
    }
}
