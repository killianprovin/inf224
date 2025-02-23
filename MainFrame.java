package swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

/**
 * Étape 2 :
 * - Ajout d'une barre de menus (JMenuBar) et d'un menu (JMenu).
 * - Ajout d'une barre d'outils (JToolBar).
 * - Utilisation d'AbstractAction pour éviter la duplication de code entre le menu et la barre d'outils.
 */
public class MainFrame extends JFrame {

    private JTextArea textArea;

    // Actions réutilisées par le menu et la barre d'outils
    private Action action1;
    private Action action2;
    private Action actionQuitter;

    public MainFrame() {
        super("Fenêtre Principale - Étape 2");

        // --- Zone de texte multi-lignes ---
        textArea = new JTextArea(8, 30);
        textArea.setLineWrap(true);
        textArea.setWrapStyleWord(true);
        JScrollPane scrollPane = new JScrollPane(textArea);

        // --- Création des Actions ---
        // Action 1
        action1 = new AbstractAction("Action 1") {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.append("Action 1 déclenchée\n");
            }
        };
        // Action 2
        action2 = new AbstractAction("Action 2") {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.append("Action 2 déclenchée\n");
            }
        };
        // Action Quitter
        actionQuitter = new AbstractAction("Quitter") {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        };

        // --- Barre de menus ---
        JMenuBar menuBar = new JMenuBar();
        JMenu menuFichier = new JMenu("Fichier");
        menuFichier.add(action1);
        menuFichier.add(action2);
        menuFichier.addSeparator();
        menuFichier.add(actionQuitter);

        menuBar.add(menuFichier);
        setJMenuBar(menuBar);

        // --- Barre d'outils ---
        JToolBar toolBar = new JToolBar("Barre d'outils");
        toolBar.add(action1);
        toolBar.add(action2);
        toolBar.addSeparator();
        toolBar.add(actionQuitter);

        // --- Mise en page (Layout) ---
        setLayout(new BorderLayout());
        add(toolBar, BorderLayout.NORTH);   // barre d'outils en haut
        add(scrollPane, BorderLayout.CENTER); // zone de texte au centre

        // Configuration de la fenêtre
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();                          // Ajuste la taille selon le contenu
        setLocationRelativeTo(null);     // Centre la fenêtre à l'écran
        setVisible(true);                // Rend la fenêtre visible
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(MainFrame::new);
    }
}
