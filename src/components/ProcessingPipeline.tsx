type StepState='idle'|'processing'|'success'|'error';
const steps=['UDP RX','JSON PARSER','SCHEMA CHECK','RANGE CHECK','SEQ CHECK'];
export default function ProcessingPipeline({active,error}:{active:number,error:boolean}){
  const stateFor=(i:number):StepState=>active<0?'idle':i<active?'success':i===active?(error?'error':'processing'):'idle';
  return <aside className="pipe"><div className="pipe-heading"><b>Telemetry Processing — SCADE Integration Mock</b><small>Referência funcional da lógica que será posteriormente integrada ao ANSYS SCADE Suite.</small></div><div className="pipe-flow">{steps.map((s,i)=><div className="pipe-step-wrap" key={s}><div className={`pipe-step ${stateFor(i)}`}><span className="step-dot"/><span>{s}</span></div>{i<steps.length-1&&<div className="pipe-arrow">↓</div>}</div>)}</div></aside>
}
