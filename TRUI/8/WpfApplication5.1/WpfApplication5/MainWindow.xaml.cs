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

namespace WpfApplication5
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

        private void OnLostFocus(object sender, RoutedEventArgs e)
        {
            Console.WriteLine("OnLostFocus");
            (sender as FrameworkElement).Style = (Style)Resources["PassiveTextBoxStyle"];
        }

        private void OnGotFocus(object sender, RoutedEventArgs e)
        {
            Console.WriteLine("OnGotFocus");
            (sender as FrameworkElement).Style = (Style)Resources["ActiveTextBoxStyle"];
        }
    }
}
