//using System;

//namespace Delegate
//{
//    delegate int MyDelegate( int a, int b );

//    class Calculator
//    {
//        public int Plus(int a, int b)
//        {
//            return a + b;
//        }

//        public static int Minus(int a, int b)
//        {
//            return a - b;
//        }
//    }

//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            Calculator Calc = new Calculator();
//            MyDelegate CallBack;

//            CallBack = new MyDelegate(Calc.Plus);
//            Console.WriteLine(CallBack(3, 4));

//            CallBack = new MyDelegate(Calculator.Minus);
//            Console.WriteLine(CallBack(7, 5));
//        }
//    }
//}