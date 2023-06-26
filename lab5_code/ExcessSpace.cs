using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace Interpreter
{
    // Неуместные пробелы
    class ExcessSpace : AbstractExpression
    {

        public ExcessSpace(int one) : base(one)
        { }

        public override void interpret(ref String context)
        { 
            context = (new Regex("([(] )+")).Replace(context, "("); //Наличие «лишнего» пробела после открывающей скобки
            context = (new Regex("( [)])+")).Replace(context, ")"); //перед закрывающей скобкой
            context = (new Regex("( ,)+")).Replace(context, ","); //перед запятой
            context = (new Regex("( [.])+")).Replace(context, "."); // перед точкой
            context = (new Regex("([“] )+")).Replace(context, "“"); // после кавычек
            context = (new Regex("( [”])+")).Replace(context, "”");  //  перед кавычек        
        }
    }
}
