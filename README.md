# C±
Most serverside platforms today use a loosely typed scripting language like Javascript (node.js) or PHP which can be infuriating for some developers who want the cold, hard cradle of type checking baked into the language. Additionally, these languages dont have any compile type checks since they're mostly interpreted. For the rare few platforms with strongly typed languages (ASP.NET / C#) you're restricted to the IIS server and large boilerplate code for your server. 

Introducing **C±**

**C±** is a strongly typed scripting language with C-like syntax for serverside platforms. When completed, it will run on apache and nginx through plugins and allow you to write either small and quick scripts for your site or larger, OOP style projects for your platforms.

#Code Examples

Your code could look like this:

    String messages = "<ul>";
    
    for(int i = 0; i < 10; i ++)
    {
        messages += "<li>Value: " + i + "</li>";    
    }
    
    messages += "</ul>";
    
or Object Oriented like this:

    class UnorganizedList
    {
        List elements;
        
        UnorganizedList()
        {
            elements = new List();
        }
        
        void add(String element)
        {
            elements.add(element);
        }
        
        String toString()
        {
            String value = "<ul>";
            
            for(int i = 0; i < elements.size(); i ++)
            {
                value += "<li>" + elements.get(i) + "</li>";
            }
            
            value += "</ul>";
            
            return value;
        }
    }
    
    UnorganizedList myList = new UnorganizedList();
    
    for(int i = 0; i < 10; i ++)
    {
        myList.add(i + "");
    }

#Printing To A Page
*"But how do I print to a page?"*, you ask. Like this!

*indexCode.cpm*

    String messages = "<ul>";
    
    for(int i = 0; i < 10; i ++)
    {
        messages += "<li>Value: " + i + "</li>";    
    }
    
    messages += "</ul>";

*index.cpm*

    import "indexCode.cpm";
    
    <html>
        <body>
            {{messages}}
        </body>
    </html>
