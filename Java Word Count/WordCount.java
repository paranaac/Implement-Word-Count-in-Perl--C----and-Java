// Author: Alejandro Parana
// Date: 3/20/2016
// WordCount Java

import java.io.*;
import java.util.*;
import java.util.Map.*;

public class WordCount {
	public static void main(String[]args) throws IOException {
		countWords("words.txt");
	}
	public static void countWords(String fileName) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(fileName));
		HashMap<String, Integer> hash = new HashMap<String, Integer>(); 
		String line, word, symbols = " .";
		
		for (int i = 1; ((line = in.readLine()) != null); i++) {
			StringTokenizer t = new StringTokenizer(line, symbols);
			while(t.hasMoreElements()) {
				word = t.nextToken().toUpperCase();
				if (!hash.containsKey(word)) {
					hash.put(word, 1);
				}
				else {
					int occurrence = hash.get(word) + 1;
					hash.put(word, occurrence);
				}
			}
		}
		System.out.println("========RESULTS===========");
		for (Entry<String, Integer> entry: hash.entrySet()) {
			String key = entry.getKey();
			Integer value = entry.getValue();
			if (value == 1)
				System.out.println(key + " was used " + value + " time.");
			else
				System.out.println(key + " was used " + value + " times.");
		}
		System.out.println("==========================");
	}
}

