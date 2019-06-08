using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScoreManager : MonoBehaviour
{
    // Start is called before the first frame update
    public Text ScoreText;
    public GameObject Player;

    public float Score = 0;

    public float PointsPerSecond = 14;
    public bool isAlive = true;

    void Update()
    {
        ScoreText.text = "Score: " + Mathf.Round(Score);
        if (isAlive) 
        {
            Score += PointsPerSecond * Time.deltaTime;
        }
    }
}
