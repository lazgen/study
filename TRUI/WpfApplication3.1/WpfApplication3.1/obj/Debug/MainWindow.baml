   M S B A M L   `   `   `  ����L  HWpfApplication3.1, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null7 clr-namespace:WpfApplication3._1WpfApplication3._1  5   	   #    WpfApplication3._1.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   2local clr-namespace:WpfApplication3._1     5   	     � Title$  
MainWindow��5   	   $	��350��6   $	��525��6)   .��5
      ]� -   5         ]�Name$ bodyItem��5
      
 � Tag$
 Body��6   .+�5   
   o� Menu��$	��Top=�6   .@�5      m� -   5        $
 File��5      $��_File��6"   .@�5      �� m� 5      -   5        $ Close��5      $��_Close��6'   6U   5      m� 5      -   5        $ 	MenuColor��5      $��_Color��6'   .@�5      m� -   5        $ White��5      
�������$��_White��6:   6h   m� 5      -   5        $	 Red��5      
���  ��$
��_Red��6:   6h   m� 5      -   5        $ Green��5      
��� � �$��_Green��6:   6h   m� 5      -   5        $
 Blue��5      
����  �$��_Blue��6:   6h   5      m� 5      -	   5        $ About��5      $��_About��6A   6Q   5      `� 5   
   $
 Dock��6   $	��Top=�6!    `� IsLocked . .�5      c� .@�5       �� -
   5        $ Close��5       .��6C   Close6J   �� 5!      -   5        $ About��5!      .��6C   About6J   �� 5"      6   �� 5#      .��6   Pick body color:6*   �� 5$      -   5        $ ComboBox��5$       �� SelectedIndex$ 0��6*   .@�5%      �� -   5        $ White��5%   #   ���#ffffff.��6s   White6z   �� 5&      -   5        $	 Red��5&   #   ���#ff0000.��6s   Red6x   �� 5'      -   5        $ Green��5'   #   ���#00ff00.��6s   Green6z   �� 5(      -   5        $
 Blue��5(   #   ���#0000ff.��6s   Blue6y   5)      5*      5+      �� 50   
   $��Bottom=�6   .@�51      �� -   5         ��Name$ statusbarLabel��51      .��6,   ...61   52      �� 56   
   $��Center=�6   $��Center=�6-   .��6H   Hello World!6V   5:      5=      