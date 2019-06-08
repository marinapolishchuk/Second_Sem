using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEngine.Tilemaps;

public class PlatformGenerator : MonoBehaviour
{
    public GameObject Platform;
    public Transform GenerationPoint;
    private float PlatformWidth;
    
    public ObjectPooler objectPool;

    void Start()
    {
        PlatformWidth = Platform.GetComponentInChildren<TilemapCollider2D>().bounds.size.x;
    }

    void Update()
    {
        if(transform.position.x < GenerationPoint.position.x) 
        {
            transform.position = new Vector3(transform.position.x + PlatformWidth, transform.position.y, transform.position.z);
            // Instantiate(Platform, transform.position, transform.rotation);
            GameObject obj = objectPool.GetPooledObject();
            obj.transform.position = transform.position;
            obj.transform.rotation = transform.rotation;
            obj.SetActive(true);
        }
    }
}
