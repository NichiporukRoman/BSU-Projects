package FileWork;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

import Rules.BackwardIndexer;
import Rules.Fact;
import Rules.ForwardIndexer;
import Rules.Rule;

public class Parser {
	private ForwardIndexer forwardIndexer = new ForwardIndexer();
	private BackwardIndexer backwardIndexer = new BackwardIndexer();
	private String filename;
	private int rules = 0;
	
	public Parser(String filename) {
		this.filename = filename;
	}
	
	public void parse() throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(this.filename));
		String line; 
		StringBuilder term = new StringBuilder();
		boolean merge = false;
		while((line = reader.readLine()) != null) {
			line = new String(line.getBytes(), "UTF-8");
			String trimedLine = line.trim();
			String[] rules = trimedLine.split(";");
			boolean termEnd = trimedLine.endsWith(";");
			int start = 0;
			int end = termEnd ? rules.length : rules.length - 1;
			if(merge) {
				term.append(rules[0]);
				if(rules.length == 1 && !termEnd) {
					continue;
				} else {
					start = 1;
					merge = false;
					dispatchRuleCreation(term.toString());
					term.setLength(0);
				}
			}
			for(int i = start; i < end; i++) {
				dispatchRuleCreation(rules[i]);
			}
			if(!termEnd) {
				merge = true;
				term.append(rules[end]);
			}
		}
		reader.close();
	}
	
	private void dispatchRuleCreation(String rule) {
		String[] ruleSides = rule.split("->");
		if(ruleSides.length < 2) {
			System.err.printf("#### ERROR: rule '%s' syntax error! skipping the rule...\n", rule);
		}
		List<Fact> conditions = parseRulePart(ruleSides[0]);
		List<Fact> conclusions = parseRulePart(ruleSides[1]);
		Rule currentRule = new Rule(conditions, conclusions);
		rules++;
		for(Fact f : conclusions) {
			backwardIndexer.registerRule(f.getLeft(), currentRule);
		}
	}
	
	private List<Fact> parseRulePart(String subrule) {
		List<Fact> facts = new ArrayList<Fact>();
		String[] components = subrule.trim().split("&");
		for(String c : components) {
			String[] parts = c.trim().split("=");
			if(parts.length < 2) {
				System.err.printf("#### ERROR: unknown assignment '%s' in rule '%s' found! skipping the assignment...\n", c, subrule);
			}
			facts.add(this.forwardIndexer.createRule(parts[0].trim(), parts[1].trim()));
		}
		return facts;
	}
	
	public ForwardIndexer getForwardIndexer() {
		return forwardIndexer;
	}
	
	public BackwardIndexer getBackwardIndexer() {
		return backwardIndexer;
	}
	
	public int getRulesCount() {
		return rules;
	}
}
