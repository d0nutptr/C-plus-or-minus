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
    
        function void add(String element)
        {
            elements.add(element);
        }
    
        function String toString()
        {
            String value = "<ul>";
    
            for(int i = 0; i < elements.size(); i ++)
            {
                value = value + "<li>" + elements.get(i) + "</li>";
            }
    
            value = value + "</ul>";
    
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

#Example
File of all currently supported features. If you can't see it being done here, it's probably not possible (*yet*).

    import "default.m";
    
    int a = 0 ;
    boolean b = false;
    char c = '2';
    double d = 10.2;
    String str = "String values";
    
    ExtendedObj _obj = null;
    
    String value = getObjSingleton().toString();
    
    print(value);
    
    if ( getObjSingleton() != null )
    {
    	boolean var = getObjSingleton() instanceof MyObject;
    }
    
    function ExtendedObj getObjSingleton()
    {
    	if (_obj == null )
    	{
    		_obj = new ExtendedObj(false);
    	}
    	
    	return _obj;
    }
    
    class MyObject 
    {
    	boolean myBool;
    	
    	MyObject(boolean a)
    	{
    		myBool = a;
    	}
    	
    	function char getChar()
    	{
    		return '\0';
    	}
    }
    
    class ExtendedObj : MyObject
    {
    	ExtendedObj(boolean a)
    	{
    		super (a);
    	}
    	
    	function char[] getChars()
    	{
    		char[] arr = new char[2];
    		arr[0] = getChar();
    		arr[1] = getChar();
    		return arr;
    	}
    	
    	function void doNothing(int a, boolean b)
    	{
    		return ;
    	}
    	
    	function String read()
    	{
    		return "\r\n";
    	}
    	
    	function int get()
    	{
    		for (Obj a in aSet) { print(a); }
    	}
    	
    	function int getInt()
    	{
    		int value = 0;
    		
    		if (obj instanceof b)
    		{
    			for (int i = 0; i < 10; i ++)
    			{
    				value = value + i;
    			}
    		}
    		
    		return value;
    	}
    }
    
    class partial ExtendedObj
    {
    	function String toString()
    	{
    		return "test of toString()";
    	}
    }
