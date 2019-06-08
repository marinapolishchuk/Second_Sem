using UnityEngine;
using UnityEngine.SceneManagement;

public class PlayerCollision : MonoBehaviour
{
    // Start is called before the first frame update

    public GameManager gm;
    
    void OnCollisionEnter2D(Collision2D col) 
    {
        if (col.gameObject.tag == "Obstacle")
        {
            gm.RestartGame();
        }
    }
}
