﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlatformDestroyer : MonoBehaviour
{
    public GameObject PlatformDestructionPoint;

    void Start()
    {
        PlatformDestructionPoint = GameObject.Find("PlatformDestructionPoint");
    }

    // Update is called once per frame
    void Update()
    {
        if(transform.position.x < PlatformDestructionPoint.transform.position.x) 
        {
            // Destroy(gameObject);
            gameObject.SetActive(false);
        }
    }
}
