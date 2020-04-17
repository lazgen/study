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

namespace WpfApplication3._1
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

        private void MouseEnter(object sender, MouseEventArgs e)
        {
            var item = ((Control)sender).Tag.ToString();
            string text;
            switch (item)
            {
                case "Body":
                    text = "This is my body item.";
                    break;
                case "Red":
                    text = "Pick it to color by body in Red";
                    break;
                case "White":
                    text = "Pick it to color by body in White";
                    break;
                case "Green":
                    text = "Pick it to color by body in Green";
                    break;
                case "Blue":
                    text = "Pick it to color by body in Blue";
                    break;
                case "About":
                    text = "There is some info about my creator. It very pretty young man!";
                    break;
                case "Close":
                    text = "I think it is rude to leave me :(";
                    break;
                case "File":
                    text = "There is some awesome menu items";
                    break;
                case "Dock":
                    text = "This is my Dock";
                    break;
                case "ComboBox":
                case "MenuColor":
                    text = "Can you select some awecome colors for me?";
                    break;
                default:
                    text = "H'm. I don't know what is it :(";
                    break;
            }

            statusbarLabel.Content =  "(" + item + "): " + text;

        }

        private void Pick_Color(object sender, RoutedEventArgs e)
        {
            var color = ((Control)sender).Background;
            bodyItem.Background = color;   
        }

        private void MenuItem_Click(object sender, RoutedEventArgs e)
        {
            var item = ((MenuItem)sender).Header.ToString();
            Console.WriteLine("Clicked on " + item);
            switch (item)
            {
                case "_Close":
                    this.Close();
                    break;
                case "_About":
                    MessageBox.Show("This is third lab of subject 'Тхи разр.ПИ'. Created by student group 8VM71 Ibetullov Yuriy");
                    break;
            }
        }
    }
}
