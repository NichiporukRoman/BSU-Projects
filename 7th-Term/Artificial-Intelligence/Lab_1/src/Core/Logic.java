package Core;

import java.util.ArrayDeque;

import Core.LogicCommunicator.CommunicatorType;
import FileWork.FileSave;
import Rules.BackwardIndexer;
import Rules.Fact;
import Rules.Fact.FactStatus;
import Rules.ForwardIndexer;
import Rules.RulesNest;

public class Logic {

    private ArrayDeque<RulesNest> stack;
    private ForwardIndexer fw;
    private BackwardIndexer bw;
    private RulesNest currentRules = null;
    private String currentRequest = null;
    private String currentFlow = new String();
    private StringBuffer result;
    private int col = 0;

    public String getCurrentFlow() {
        return currentFlow;
    }

    public void concatCurrentFlow(String str) {
        currentFlow = currentFlow.concat(str);
    }

    public void clearCurrentFlow() {
        currentFlow = new String();
    }

    public Logic(ForwardIndexer fw, BackwardIndexer bw) {
        this.fw = fw;
        this.bw = bw;
        this.stack = new ArrayDeque<RulesNest>();
        result = new StringBuffer();
    }

    public void clear() {
        stack = new ArrayDeque<RulesNest>();
        fw.clean();
        bw.clean();
        currentRules = null;
        currentRequest = null;
    }

    public LogicCommunicator startLobby(LogicCommunicator request) {
        request.setResponseCategory("Goals");
        request.setResponse(bw.getAvailableOptions());
        request.setType(CommunicatorType.VALUE);
        return request;
    }

    public void loggerLoader(LogicCommunicator request){
        String req = request.getRequest();
            if (col == 0) {
                result.append("Goal:" + req + "\r\n");
            }
            col++;
            if (currentRequest == null) {
                currentRequest = req;
                currentRules = bw.findMatchingRules(currentRequest);
                currentFlow = currentFlow.concat(" -> ");
                result.append("\r\n");
                new FileSave("7th-Term/Artificial-Intelligence/Lab_1/log.txt", result.toString());
            } else {
                fw.satisfyFact(currentRequest, req, FactStatus.TRUE);
            }
    }

    public LogicCommunicator nextStep(LogicCommunicator request) {
        CommunicatorType type = request.getType();
        if (type == CommunicatorType.KEY) {
            request = startLobby(request);
        } else if (type == CommunicatorType.VALUE) {
            loggerLoader(request);
            while (true) {
                Fact f = currentRules == null ? null : currentRules.getUnknownFact(fw);
                if (f != null) {
                    RulesNest rn = bw.findMatchingRules(f.getLeft());
                    currentRequest = f.getLeft();
                    System.err.println();
                    if (rn == null) {
                        result.append("Question for: " + f.getLeft() + "\r\n");
                        new FileSave("7th-Term/Artificial-Intelligence/Lab_1/log.txt", result.toString());

                        request.setResponseCategory(String.format(currentRequest));
                        currentFlow = currentFlow.concat(" " + currentRequest + "=");
                        request.setResponse(fw.getAvailableOptions(currentRequest));
                        break;
                    } else {
                        stack.push(currentRules);
                        System.out.println(currentRules);
                        currentRules = rn;
                        result.append("\r\n");
                        new FileSave("7th-Term/Artificial-Intelligence/Lab_1/log.txt", result.toString());

                    }
                } else {
                    if (stack.size() == 0) {
                        String answer;
                        if (currentRules != null && currentRules.getCorrectRule() != null) {
                            answer = currentRules.getCorrectRule().getConclusion();
                        } else {
                            answer = "The answer could not be found";
                        }
                        result.append("Result: ");
                        result.append(answer + "\r\n");
                        result.append("\r\n");
                        new FileSave("7th-Term/Artificial-Intelligence/Lab_1/log.txt", result.toString());

                        request.setResponseCategory("Answer");
                        request.setType(CommunicatorType.ANSWER);
                        request.setResponse(answer);
                        col = 0;
                        break;
                    } else {
                        if (currentRules.getCorrectRule() != null) {
                            currentFlow = currentFlow.concat(" // " + currentRules.getCorrectRule().toString() + " // ");
                            result.append("The following rule applies: " + currentRules.getCorrectRule().toString() + "\r\n");
                            result.append("\r\n");
                        } else {
                        currentFlow = currentFlow.concat(" // The answer could not be found");
                            result.append("The answer could not be found\r\n");
                            result.append("\r\n");
                        }
                        currentRules = stack.pop();
                    }
                }
            }
            
        }
        return request;
    }
}
