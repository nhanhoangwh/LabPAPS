using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

// Кавычки
namespace Interpreter
{
    class Quote : AbstractExpression
    {

        public Quote(int one) : base(one)
        { }
        //исправить Кавычки
        public override void interpret(ref String context)
        {
            context = (new Regex("(“)+")).Replace(context, "«");                      
            context = (new Regex("(”)+")).Replace(context, "»");
        }
    }
}
