package Core;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class LogicCommunicator {

    private CommunicatorType type;
    private String responseCategory;
    private Collection<String> response;
    private String request;

    public LogicCommunicator(String request) {
        this.request = request;
        this.type = CommunicatorType.KEY;
    }

    public String getRequest() {
        return request;
    }

    public void setRequest(String request) {
        this.request = request;
    }

    public Collection<String> getResponse() {
        return response;
    }

    public void setResponse(Collection<String> response) {
        this.response = response;
    }

    public void setResponse(String response) {
        List<String> l = new ArrayList<String>();
        l.add(response);
        this.response = l;
    }

    public CommunicatorType getType() {
        return type;
    }

    public void setType(CommunicatorType type) {
        this.type = type;
    }

    public String getResponseCategory() {
        return responseCategory;
    }

    public void setResponseCategory(String responseCategory) {
        this.responseCategory = responseCategory;
    }

    public enum CommunicatorType {
        KEY, VALUE, ERROR, ANSWER;
    }
}
