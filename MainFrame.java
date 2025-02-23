package swing;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import java.awt.BorderLayout;
import java.awt.FlowLayout;

public class MainFrame extends JFrame {

    private JTextArea textArea;
    private JButton button1;
    private JButton button2;
    private JButton button3;

    public MainFrame() {
        super("Fenêtre Principale");
        
        // Zone de texte multi-lignes
        textArea = new JTextArea(5, 20); 
        textArea.setLineWrap(true);
        textArea.setWrapStyleWord(true);

        // On place la zone de texte dans un JScrollPane pour la barre de défilement
        JScrollPane scrollPane = new JScrollPane(textArea);
        add(scrollPane, BorderLayout.CENTER);

        // Panel pour les boutons, en bas de la fenêtre
        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 10));

        // Trois boutons
        button1 = new JButton("Bouton 1");
        button2 = new JButton("Bouton 2");
        button3 = new JButton("Quitter");

        // On ajoute les boutons au panel
        buttonPanel.add(button1);
        buttonPanel.add(button2);
        buttonPanel.add(button3);

        // Le panel de boutons est placé en bas (SOUTH)
        add(buttonPanel, BorderLayout.SOUTH);

        // Configuration basique de la fenêtre
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();                     // Ajuste la taille en fonction du contenu
        setLocationRelativeTo(null); // Centre la fenêtre à l’écran
        setVisible(true);

        // Actions sur les boutons
        button1.addActionListener(e -> textArea.append("Ligne ajoutée par Bouton 1\n"));
        button2.addActionListener(e -> textArea.append("Ligne ajoutée par Bouton 2\n"));
        button3.addActionListener(e -> System.exit(0));
    }

    public static void main(String[] args) {
        new MainFrame();
    }
}
