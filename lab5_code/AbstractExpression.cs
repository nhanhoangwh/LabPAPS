using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    class AbstractExpression
    {
        private AbstractExpression manySpace, hyphenDash, quote, manyTabs, excessSpace, lineFeeds;

        public AbstractExpression()
        {
            manySpace = new ManySpace(1);   // Множественные пробелы
            hyphenDash = new HyphenDash(1); // Дефис вместо тире
            quote = new Quote(1);   // Кавычки
            manyTabs = new МanyTabs(1); // Неуместные табуляторы
            excessSpace = new ExcessSpace(1);  // Неуместные пробелы
            lineFeeds = new LineFeeds(1);   // Множественные переводы строки
        }
        public AbstractExpression(int one)
        {                    
        }
        //для редактирования текста
        public virtual void interpret(ref String context)
        {
            manySpace.interpret(ref context); //исправить множественные пробелы
            hyphenDash.interpret(ref context); //исправить дефис
            quote.interpret(ref context); //исправить Кавычки
            manyTabs.interpret(ref context); //исправить Неуместные табуляторы
            excessSpace.interpret(ref context); //исправить Неуместные пробелы
            lineFeeds.interpret(ref context); //исправить Множественные переводы строки
        }
    }
}
