package GUI;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.SwingUtilities;

import Core.Logic;
import Core.LogicCommunicator;
import Core.LogicCommunicator.CommunicatorType;
import FileWork.Parser;

public class Main extends JFrame implements ActionListener {

    public static void main(String args[]) throws Exception {
        SwingUtilities.invokeAndWait(new Runnable() {
            @Override
            public void run() {
                try {
                    JFrame me = new Main("7th-Term/Artificial-Intelligence/Lab_1/rules.txt");
                    me.setVisible(true);
                    me.setDefaultCloseOperation(EXIT_ON_CLOSE);
                } catch (Exception exc) {
                    System.err.println("Unexpected error. " + exc.getMessage());
                    exc.printStackTrace();
                }
            }
        });
    }
    public static int MAX_ANSW_SIZE = 16;
    private JLabel statusBar = new JLabel("");
    private JLabel totalRulesBar = new JLabel("Number of rules: 0");
    private JPanel centralPanel = new JPanel();
    private JPanel upperPanel = new JPanel();
    private JPanel lowerPanel = new JPanel();
    private JButton select = new JButton("Confirm");
    private JLabel curFlow = new JLabel();
    private LogicCommunicator cc;
    private JRadioButton[] selButtons = new JRadioButton[MAX_ANSW_SIZE];
    private ButtonGroup selGroup = new ButtonGroup();
    private Logic currentCore;

    public Main(String path) throws Exception {
        setTitle("Analyser");
        setSize(600, 600);
        setLocation(300, 50);
        currentCore = reloadKnowledgeBase(path);

        select.addActionListener(this);

        final JButton itemStart = new JButton("Start");
        final JButton itemExit = new JButton("Exit");
        final JButton itemBack = new JButton("Rerun");

        itemStart.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                cc = new LogicCommunicator(null);
                if (select != null) {
                    select.setVisible(true);
                    select.setEnabled(true);
                    currentCore.clear();
                    cc = currentCore.nextStep(cc);
                    doSetView();
                }
                currentCore.clearCurrentFlow();
                curFlow.setText("");
                itemStart.setEnabled(false);
                itemStart.setVisible(false);
            }
        });

        itemExit.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        itemBack.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    String java = System.getProperty("java.home") + "/bin/java";
                    String classpath = System.getProperty("java.class.path");
                    String mainClass = Main.class.getCanonicalName();
                    ProcessBuilder builder = new ProcessBuilder(java, "-cp", classpath, mainClass);
                    builder.start();
                    System.exit(0);
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });

        upperPanel.setLayout(new GridLayout(5, 1));
        upperPanel.setBorder(BorderFactory.createEtchedBorder());
        upperPanel.add(totalRulesBar);
        upperPanel.add(statusBar);
        upperPanel.add(itemExit);
        upperPanel.add(itemBack);
        upperPanel.add(itemStart);

        centralPanel.setLayout(new GridLayout(MAX_ANSW_SIZE + 1, 1));

        for (int i = 0; i < MAX_ANSW_SIZE; i++) {
            selButtons[i] = new JRadioButton();
            selGroup.add(selButtons[i]);
            centralPanel.add(selButtons[i]);
        }

        JPanel b = new JPanel(new GridLayout(1, 3));
        b.add(new JPanel());
        b.add(select);
        b.add(new JPanel());

        lowerPanel.add(curFlow);

        centralPanel.add(b);
        add(upperPanel, BorderLayout.NORTH);
        add(centralPanel, BorderLayout.CENTER);
        add(lowerPanel, BorderLayout.SOUTH);

        cleanCentralPanel();
    }

    private Logic reloadKnowledgeBase(String pathToBase) throws Exception {
        if (pathToBase != null) {
            Parser parser = new Parser(pathToBase);
            parser.parse();
            statusBar.setText("Knowledge base loaded");
            totalRulesBar.setText(String.format("Number of rules: %d", parser.getRulesCount()));
            return new Logic(parser.getForwardIndexer(), parser.getBackwardIndexer());
        }
        return null;
    }

    private void cleanCentralPanel() {
        for (JRadioButton rb : selButtons) {
            rb.setVisible(false);
        }
        select.setVisible(false);
    }

    private void doSetView() {
        if (cc.getType() == CommunicatorType.ANSWER) {
            select.setEnabled(false);
        }
        statusBar.setText("<html><h3>" + cc.getResponseCategory() + "</h3></html>");
        int i = 0;
        selButtons[0].setSelected(true);
        for (String category : cc.getResponse()) {
            selButtons[i].setText(category);
            selButtons[i].setVisible(true);
            i++;
        }
        for (int j = i; j < MAX_ANSW_SIZE; j++) {
            selButtons[j].setVisible(false);
        }

    }

    @Override
    public void actionPerformed(ActionEvent ae) {
        for (JRadioButton rb : selButtons) {
            if (rb.isSelected()) {
                cc.setRequest(rb.getText());
                currentCore.concatCurrentFlow(rb.getText());
                curFlow.setText(currentCore.getCurrentFlow());
                break;
            }
        }
        cc = currentCore.nextStep(cc);
        doSetView();
    }
}
