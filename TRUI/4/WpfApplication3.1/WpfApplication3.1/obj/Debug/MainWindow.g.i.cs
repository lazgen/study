﻿#pragma checksum "..\..\MainWindow.xaml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "ADDF97C0D86FED10DA4E5B446C28B2696B994622"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;
using WpfApplication3._1;


namespace WpfApplication3._1 {
    
    
    /// <summary>
    /// MainWindow
    /// </summary>
    public partial class MainWindow : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 11 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.DockPanel bodyItem;
        
        #line default
        #line hidden
        
        
        #line 20 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MenuItem ColorMenu;
        
        #line default
        #line hidden
        
        
        #line 37 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ComboBox ColorComboBox;
        
        #line default
        #line hidden
        
        
        #line 50 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label statusbarLabel;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/WpfApplication3.1;component/mainwindow.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\MainWindow.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            this.bodyItem = ((System.Windows.Controls.DockPanel)(target));
            return;
            case 2:
            
            #line 15 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).AddHandler(System.Windows.Input.Mouse.MouseEnterEvent, new System.Windows.Input.MouseEventHandler(this.MouseEnter));
            
            #line default
            #line hidden
            return;
            case 3:
            
            #line 18 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).AddHandler(System.Windows.Input.Mouse.MouseEnterEvent, new System.Windows.Input.MouseEventHandler(this.MouseEnter));
            
            #line default
            #line hidden
            
            #line 18 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click);
            
            #line default
            #line hidden
            return;
            case 4:
            this.ColorMenu = ((System.Windows.Controls.MenuItem)(target));
            
            #line 20 "..\..\MainWindow.xaml"
            this.ColorMenu.AddHandler(System.Windows.Input.Mouse.MouseEnterEvent, new System.Windows.Input.MouseEventHandler(this.MouseEnter));
            
            #line default
            #line hidden
            return;
            case 5:
            
            #line 21 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).AddHandler(System.Windows.Input.Mouse.MouseEnterEvent, new System.Windows.Input.MouseEventHandler(this.MouseEnter));
            
            #line default
            #line hidden
            
            #line 21 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.Pick_Color);
            
            #line default
            #line hidden
            return;
            case 6:
            
            #line 22 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).AddHandler(System.Windows.Input.Mouse.MouseEnterEvent, new System.Windows.Input.MouseEventHandler(this.MouseEnter));
            
            #line default
            #line hidden
            
            #line 22 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.Pick_Color);
            
            #line default
            #line hidden
            return;
            case 7:
            
            #line 23 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).AddHandler(System.Windows.Input.Mouse.MouseEnterEvent, new System.Windows.Input.MouseEventHandler(this.MouseEnter));
            
            #line default
            #line hidden
            
            #line 23 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.Pick_Color);
            
            #line default
            #line hidden
            return;
            case 8:
            
            #line 24 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).AddHandler(System.Windows.Input.Mouse.MouseEnterEvent, new System.Windows.Input.MouseEventHandler(this.MouseEnter));
            
            #line default
            #line hidden
            
            #line 24 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.Pick_Color);
            
            #line default
            #line hidden
            return;
            case 9:
            
            #line 26 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).AddHandler(System.Windows.Input.Mouse.MouseEnterEvent, new System.Windows.Input.MouseEventHandler(this.MouseEnter));
            
            #line default
            #line hidden
            
            #line 26 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click);
            
            #line default
            #line hidden
            return;
            case 10:
            
            #line 33 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.Button)(target)).AddHandler(System.Windows.Input.Mouse.MouseEnterEvent, new System.Windows.Input.MouseEventHandler(this.MouseEnter));
            
            #line default
            #line hidden
            return;
            case 11:
            
            #line 34 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.Button)(target)).AddHandler(System.Windows.Input.Mouse.MouseEnterEvent, new System.Windows.Input.MouseEventHandler(this.MouseEnter));
            
            #line default
            #line hidden
            return;
            case 12:
            this.ColorComboBox = ((System.Windows.Controls.ComboBox)(target));
            
            #line 37 "..\..\MainWindow.xaml"
            this.ColorComboBox.AddHandler(System.Windows.Input.Mouse.MouseEnterEvent, new System.Windows.Input.MouseEventHandler(this.MouseEnter));
            
            #line default
            #line hidden
            return;
            case 13:
            
            #line 38 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.ComboBoxItem)(target)).MouseEnter += new System.Windows.Input.MouseEventHandler(this.MouseEnter);
            
            #line default
            #line hidden
            return;
            case 14:
            
            #line 39 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.ComboBoxItem)(target)).MouseEnter += new System.Windows.Input.MouseEventHandler(this.MouseEnter);
            
            #line default
            #line hidden
            return;
            case 15:
            
            #line 40 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.ComboBoxItem)(target)).MouseEnter += new System.Windows.Input.MouseEventHandler(this.MouseEnter);
            
            #line default
            #line hidden
            return;
            case 16:
            
            #line 41 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.ComboBoxItem)(target)).MouseEnter += new System.Windows.Input.MouseEventHandler(this.MouseEnter);
            
            #line default
            #line hidden
            return;
            case 17:
            this.statusbarLabel = ((System.Windows.Controls.Label)(target));
            return;
            }
            this._contentLoaded = true;
        }
    }
}

