using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{

    public Transform PlatformGenerator;
    public GameObject Player;
    public GameObject StartPlatform;
    public ScoreManager sm;
    private Vector3 platformStart;
    private Vector3 playerStart;
    // Start is called before the first frame update
    void Start()
    {
        platformStart = PlatformGenerator.position;
        playerStart = Player.transform.position; 
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetButton("Cancel")) {
            Application.Quit();
        }
    }

    public void RestartGame()
    {
        StartCoroutine("RestartGameCo");
    }

    public IEnumerator RestartGameCo() 
    {
        Player.gameObject.SetActive(false);
        sm.isAlive = false;
        yield return new WaitForSeconds(0.5f);
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }

}
