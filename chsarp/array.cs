using System;
class Program {

    public static void Main(string[] args){

        Console.WriteLine("daysOfWeek:");
        string [] daysOfWeek = {
            "Monday",
            "Tuesday",
            "Wednesday"
        };

        List<string> weekend = new List<string>();
        weekend.Add("Saturday");
        weekend.Add("Sunday");

        foreach (var day in weekend){
            Console.WriteLine(day);
        }

        int[] intArr = {1,2,3};

        foreach (var elem in intArr){
            Console.WriteLine(elem);
        };

        List<string> otherDays = new List<string>();
        otherDays.Add("Thursday");
        otherDays.Add("Friday");

        List<string> weekends = new List<string>(){
            "Saturday",
            "Sunday"
        };
    
        foreach (var day in weekends){
            Console.WriteLine(day);
        }

    }
}

Program.Main(null); 