using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObstacleGenerator : MonoBehaviour
{

    public Transform GenerationPoint;
    public int MinInterval = 3;
    public int MaxInterval = 8;
    public List<ObjectPooler> ObjectPoolers;



    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        int objIndx = Random.Range(0, ObjectPoolers.Count);
        if (transform.position.x < GenerationPoint.position.x) {
            int objectX = Random.Range(MinInterval, MaxInterval);
            transform.position = new Vector3(transform.position.x + objectX, transform.position.y, transform.position.z);
            GameObject obj = ObjectPoolers[objIndx].GetPooledObject();
            obj.transform.position = transform.position;
            obj.transform.rotation = transform.rotation;
            obj.SetActive(true);
        }
    }
}
