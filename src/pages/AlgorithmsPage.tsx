import{useEffect,useMemo,useState}from'react';import Prism from'prismjs';import'prismjs/components/prism-c';import'prismjs/themes/prism-tomorrow.css';
const names=['telemetry_types.h','telemetry_parser.c','telemetry_parser.h','telemetry_validator.c','telemetry_validator.h','telemetry_sequence.c','telemetry_sequence.h','telemetry_pipeline.c','telemetry_pipeline.h','udp_receiver.c','udp_receiver.h','demo_main.c'];
const descriptions:Record<string,string>={
 'telemetry_types.h':'Define as estruturas e enumerações tipadas usadas pelo pipeline de telemetria.',
 'telemetry_parser.c':'Converte o JSON bruto recebido por UDP em uma estrutura TelemetryPacket tipada para processamento pela lógica do sistema.',
 'telemetry_parser.h':'Expõe a interface pública do parser de telemetria.',
 'telemetry_validator.c':'Aplica as regras de faixa e consistência aos campos já desempacotados.',
 'telemetry_validator.h':'Define o contrato e o resultado da etapa de validação.',
 'telemetry_sequence.c':'Verifica continuidade, lacunas e duplicidade da sequência de pacotes.',
 'telemetry_sequence.h':'Define o estado persistente e a interface do verificador de sequência.',
 'telemetry_pipeline.c':'Orquestra parser, validação e verificação de sequência em um único fluxo.',
 'telemetry_pipeline.h':'Expõe o estado e a interface pública do pipeline.',
 'udp_receiver.c':'Isola a recepção UDP via Winsock2 do núcleo de processamento.',
 'udp_receiver.h':'Define a interface mínima do receptor UDP.',
 'demo_main.c':'Demonstra a integração do receptor UDP com o pipeline C em um executável de console.'
};
function CodeEditor({code,name}:{code:string;name:string}){const html=useMemo(()=>Prism.highlight(code,Prism.languages.c,'c'),[code]);const lines=code.split('\n');return <div className="ide"><div className="ide-tab"><b>{name}</b><span>C</span></div><div className="code-scroll"><div className="line-numbers" aria-hidden="true">{lines.map((_,i)=><span key={i}>{i+1}</span>)}</div><pre className="code language-c"><code dangerouslySetInnerHTML={{__html:html}}/></pre></div></div>}
export default function AlgorithmsPage(){const[n,setN]=useState(names[1]),[code,setCode]=useState('');useEffect(()=>{fetch(`${import.meta.env.BASE_URL}c-algorithms/${n}`).then(r=>r.text()).then(setCode)},[n]);return <main className="page algorithms-page"><div className="hero"><h1>US123 — Telemetry Processing Algorithms</h1><p>Implementação de referência em C para recepção, desempacotamento e validação de telemetria, organizada para futura integração com o ANSYS SCADE Suite.</p></div><div className="algoGrid"><aside className="file-sidebar"><h3>FILES</h3>{names.map(x=><button key={x} className={x===n?'active':''} onClick={()=>setN(x)}>{x}</button>)}</aside><section className="editor-column"><div className="file-description"><b>{n}</b><span><strong>Responsabilidade:</strong> {descriptions[n]}</span></div><CodeEditor code={code} name={n}/><div className="download-row"><a className="button-link" href={`${import.meta.env.BASE_URL}c-algorithms/${n}`} download>Download File</a><a className="button-link primary" href={`${import.meta.env.BASE_URL}US123_C_Algorithms.zip`} download>Download All C Algorithms</a></div></section></div></main>}
