using System;
using System.IO;

class Program{
    private static readonly string FILE_PATH = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments), "CC223");

    static bool CheckFile(string filePath)
    {
        return File.Exists(filePath);
    }

    static void WritingTextToFile(string filePath, FileMode mode)
    {
        try
        {
            using (FileStream fs = new FileStream(filePath, mode, FileAccess.Write))
            using (StreamWriter writer = new StreamWriter(fs))
            {
                Console.Write("\nWrite a text for your file: ");
                string text = Console.ReadLine();
                writer.WriteLine(text);
                Console.WriteLine("✅ File written successfully.");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($" Error writing to file: {ex.Message}");
        }
    }

    static void CreateFile()
    {
        Console.Write("\nEnter file name to create: ");
        string fileName = Console.ReadLine();
        string filePath = Path.Combine(FILE_PATH, fileName);

        try
        {
            if (!Directory.Exists(FILE_PATH))
                Directory.CreateDirectory(FILE_PATH);

            if (CheckFile(filePath))
            {
                Console.WriteLine("\n File already exists.");
                return;
            }

            using (File.Create(filePath)) { }
            Console.WriteLine(" File created successfully.");
        }
        catch (Exception ex)
        {
            Console.WriteLine($" Error creating file: {ex.Message}");
        }
    }

    static void WriteFile()
    {
        Console.Write("\nEnter the file name you want to write to: ");
        string fileName = Console.ReadLine();
        string filePath = Path.Combine(FILE_PATH, fileName);

        if (!CheckFile(filePath))
        {
            Console.WriteLine("\n File not found.");
            return;
        }

        try
        {
            string content = File.ReadAllText(filePath);
            if (!string.IsNullOrEmpty(content))
            {
                Console.Write("\nThe file already contains text. Do you want to (O)Overwrite or (A)Append? ");
                char choice = Console.ReadKey().KeyChar;
                Console.WriteLine();

                if (choice == 'O' || choice == 'o')
                    WritingTextToFile(filePath, FileMode.Create);
                else if (choice == 'A' || choice == 'a')
                    WritingTextToFile(filePath, FileMode.Append);
                else
                    Console.WriteLine("\n Invalid choice. No changes made.");
            }
            else
            {
                WritingTextToFile(filePath, FileMode.Create);
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($" Error writing to file: {ex.Message}");
        }
    }

    static void Main()
    {
        int key;
        Console.WriteLine("- - -  FILE HANDLING SYSTEM  - - -");

        do
        {
            Console.WriteLine("\n[1] Create File\n[2] Write to a File\n[3] Exit Program");
            Console.Write("> ");
            if (!int.TryParse(Console.ReadLine(), out key))
            {
                Console.WriteLine(" Please choose a valid option.");
                continue;
            }

            switch (key)
            {
                case 1:
                    CreateFile();
                    break;
                case 2:
                    WriteFile();
                    break;
                case 3:
                    Console.WriteLine(" At your service sir.");
                    return;
                default:
                    Console.WriteLine(" Please choose a valid option.");
                    break;
            }

        } while (key != 3);
    }
}
