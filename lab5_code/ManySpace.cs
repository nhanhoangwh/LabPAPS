using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace Interpreter
{
    // Множественные пробелы
    class ManySpace : AbstractExpression
    {

        public ManySpace(int one) : base(one)
        { }

        public override void interpret(ref String context)
        { 
            context = (new Regex("\\s+")).Replace(context, " ");           
        }
    }
}
